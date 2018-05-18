package answerCode;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import model.PlaceInfo;

public class P1798 {

	private static final int AIRPORT = 0;
	private static final int POINT = 1;
	private static final int HOTEL = 2;
	private static final int MAX_TIME = 60 * 9;

	private int[][] courses;
	private PlaceInfo[] placeInfoes;
	private int n;
	private int m;

	private int maxSatisfaction;
	private List<Integer> maxCourse;

	private boolean[] visited;
	private List<Integer> nowCourse;
	private int nowSatisfaction;
	
	private List<Cache> cache;

	public P1798(int[][] courses, PlaceInfo[] placeInfoes, int n, int m) {
		this.courses = courses;
		this.placeInfoes = placeInfoes;
		this.n = n;
		this.m = m;

		maxSatisfaction = 0;
		maxCourse = new ArrayList<Integer>();
		visited = new boolean[n];
		nowCourse = new ArrayList<Integer>();
		nowSatisfaction = 0;
		
		cache = new ArrayList<Cache>();
	}

	public List<Integer> solution() {
		int airport = -1;

		for (int i = 0; i < n; i++) {
			if (placeInfoes[i].getBuilding() == AIRPORT) {
				airport = i;
				break;
			}
		}

		sol(airport, 1, 0);

		maxCourse.add(0, maxSatisfaction);

		return maxCourse;
	}

	private void sol(int start, int day, int time) {

		for (int i = 0; i < n; i++) {

			if (placeInfoes[i].getBuilding() == POINT && visited[i] == false) {
				visited[i] = true;
				nowSatisfaction += placeInfoes[i].getSatisfaction();

				time += courses[start][i];
				time += placeInfoes[i].getPlay();
				nowCourse.add(i);
				int idx = nowCourse.size() - 1;

				if (time <= MAX_TIME)
					sol(i, day, time);

				time -= courses[start][i];
				time -= placeInfoes[i].getPlay();
				nowCourse.remove(idx);

				visited[i] = false;
				nowSatisfaction -= placeInfoes[i].getSatisfaction();
			} else if (placeInfoes[i].getBuilding() == HOTEL && day < m) {
				time += courses[start][i];
				nowCourse.add(i);
				int idx = nowCourse.size() - 1;

				if (time <= MAX_TIME)
					sol(i, day + 1, 0);

				time -= courses[start][i];
				nowCourse.remove(idx);
			} else if (placeInfoes[i].getBuilding() == AIRPORT && day == m) {
				time += courses[start][i];
				nowCourse.add(i);
				int idx = nowCourse.size() - 1;

				if (time <= MAX_TIME && maxSatisfaction < nowSatisfaction) {
					maxSatisfaction = nowSatisfaction;
					maxCourse.clear();
					maxCourse.addAll(nowCourse);
				}

				time -= courses[start][i];
				nowCourse.remove(idx);
			}
		}
	}
}

class Solution {
	public static void main(String args[]) {

		Scanner input = new Scanner(System.in);

		int testSize = input.nextInt();

		for (int t = 0; t < testSize; t++) {

			int n = input.nextInt();
			int m = input.nextInt();

			int[][] courses = new int[n][n];

			for (int i = 0; i < n; i++)
				courses[i][i] = 0;

			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					int dist = input.nextInt();
					courses[i][j] = dist;
					courses[j][i] = dist;
				}
			}

			PlaceInfo[] placeInfoes = new PlaceInfo[n];
			for (int i = 0; i < n; i++)
				placeInfoes[i] = new PlaceInfo();

			for (int i = 0; i < n; i++) {
				String building = input.next();

				if (building.equals("A"))
					placeInfoes[i].setBuildng(0);
				else if (building.equals("H"))
					placeInfoes[i].setBuildng(2);
				else if (building.equals("P")) {
					placeInfoes[i].setBuildng(1);

					int play = input.nextInt();
					int satisfaction = input.nextInt();

					placeInfoes[i].setPlay(play);
					placeInfoes[i].setSatisfaction(satisfaction);
				}
			}

			P1798 p1798 = new P1798(courses, placeInfoes, n, m);
			List<Integer> answer = p1798.solution();

			System.out.print("#" + (t + 1) + " ");
			for (int i = 0; i < answer.size(); i++) {
				if (i != 0)
					System.out.print(answer.get(i) + 1 + " ");
				else
					System.out.print(answer.get(i) + " ");
			}
			System.out.println();
		}

		input.close();

	}
}

class Cache {
	List<Integer> course;

	public Cache(List<Integer> course) {
		this.course = course;
	}

	public boolean isEqual(List<Integer> cmp) {
		for (int i = 0; i < course.size(); i++) {
			if (cmp.size() == i || course.get(i) != cmp.get(i))
				return false;
		}
		return true;
	}
}
