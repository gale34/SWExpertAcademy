package test;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import org.junit.jupiter.api.Test;

import answerCode.P1859;

class SampleTest {

	P1859 p1869Test = new P1859();

	@Test
	void P1859test() {

		File file = new File("resource/P1859Input.txt");

		Scanner input;
		try {
			input = new Scanner(file);

			int testSize = input.nextInt();

			for (int t = 0; t < testSize; t++) {
				int n = input.nextInt();

				int prices[] = new int[n];
				for (int i = 0; i < n; i++) {
					prices[i] = input.nextInt();
				}

				long answer = p1869Test.solution(prices);

				System.out.println("#" + (t + 1) + " " + answer);
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
