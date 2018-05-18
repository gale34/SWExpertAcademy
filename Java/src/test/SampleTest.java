package test;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.Scanner;

import org.junit.jupiter.api.Test;

import answerCode.P1859;
import answerCode.P2806;
import model.PlaceInfo;
import answerCode.P1798;

class SampleTest {

	/*
	 * @Test void P1859test() {
	 * 
	 * File file = new File("resource/P1859Input.txt");
	 * 
	 * Scanner input; try { input = new Scanner(file);
	 * 
	 * int testSize = input.nextInt();
	 * 
	 * for (int t = 0; t < testSize; t++) { int n = input.nextInt();
	 * 
	 * int prices[] = new int[n]; for (int i = 0; i < n; i++) { prices[i] =
	 * input.nextInt(); }
	 * 
	 * long answer = P1859.solution(prices);
	 * 
	 * System.out.println("#" + (t + 1) + " " + answer); }
	 * 
	 * } catch (FileNotFoundException e) { // TODO Auto-generated catch block
	 * e.printStackTrace(); } }
	 * 
	 * @Test void P2806Test() {
	 * 
	 * File file = new File("resource/P2806Input.txt");
	 * 
	 * Scanner input; try { input = new Scanner(file);
	 * 
	 * int testSize = input.nextInt();
	 * 
	 * for (int t = 0; t < testSize; t++) {
	 * 
	 * int n = input.nextInt(); P2806 p2806 = new P2806(n);
	 * 
	 * p2806.solution(0); int answer = p2806.getAnswer();
	 * 
	 * System.out.println("#" + (t + 1) + " " + answer); }
	 * 
	 * } catch (FileNotFoundException e) { // TODO Auto-generated catch block
	 * e.printStackTrace(); } }
	 */

	@Test
	void P1798Test() {

		File file = new File("resource/P1798Input.txt");

		Scanner input;

		try {
			input = new Scanner(file);

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
					if(i != 0)
						System.out.print(answer.get(i) + 1 + " ");
					else
						System.out.print(answer.get(i) + " ");
				}
				System.out.println();
			}

			input.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
