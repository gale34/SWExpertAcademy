package answerCode;

import java.util.Scanner;

public class P2806 {

	private int answer;
	private int[] queen;
	private int size;

	public P2806(int n) {
		queen = new int[n];
		size = n;
	}

	public int getAnswer() {
		return answer;
	}

	private boolean checkQueen(int target) {
		for (int i = 0; i < target; i++) {
			if (queen[i] == queen[target])
				return false;
			else if (Math.abs(queen[i] - queen[target]) == Math.abs(i - target))
				return false;
		}

		return true;
	}

	public void solution(int target) {
		if (target == size) {
			answer++;
			return;
		}

		for (int i = 0; i < size; i++) {
			queen[target] = i;
			if (checkQueen(target))
				solution(target + 1);
		}
	}

	public static void main(String args[]) {

		Scanner input = new Scanner(System.in);

		int testSize = input.nextInt();

		for (int t = 0; t < testSize; t++) {

			int n = input.nextInt();
			P2806 p2806 = new P2806(n);

			p2806.solution(0);
			int answer = p2806.getAnswer();

			System.out.println("#" + (t + 1) + " " + answer);
		}

		input.close();

	}
}
