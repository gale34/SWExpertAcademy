package test;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import org.junit.jupiter.api.Test;

import answerCode.P1859;
import answerCode.P2806;

class SampleTest {
	
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

				long answer = P1859.solution(prices);

				System.out.println("#" + (t + 1) + " " + answer);
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Test
	void P2806Test() {

		File file = new File("resource/P2806Input.txt");
		
		Scanner input;
		try {
			input = new Scanner(file);

			int testSize = input.nextInt();
			
			for (int t = 0; t < testSize; t++) {

				
				int n = input.nextInt();
				P2806 p2806 = new P2806(n);
				
				p2806.solution(0);
				int answer = p2806.getAnswer();

				System.out.println("#" + (t + 1) + " " + answer);
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
