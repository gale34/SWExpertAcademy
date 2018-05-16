package answerCode;

import java.util.Scanner;

public class P1859 {
	public static long solution(int[] prices) {
		int n = prices.length;
		long answer = 0;

		int start = 0;

		while (start < n) {
			long sum = 0;
			long maxPrice = 0;
			long maxSum = 0;
			int maxIdx = 1;

			for (int i = start; i < n; i++) {
				sum += prices[i];
				if (maxPrice <= prices[i]) {
					maxPrice = prices[i];
					maxSum = sum;
					maxIdx = i;
				}
			}

			answer += maxPrice * (maxIdx - start + 1) - maxSum;
			start = maxIdx + 1;
		}

		return answer;
	}

	public static void main(String args[]) {

		Scanner input = new Scanner(System.in);

		int testSize = input.nextInt();

		for (int t = 0; t < testSize; t++) {
			int n = input.nextInt();

			int prices[] = new int[n];
			for (int i = 0; i < n; i++) {
				prices[i] = input.nextInt();
			}

			long answer = solution(prices);

			System.out.println("#" + (t + 1) + " " + answer);
		}
		
		input.close();

	}
}