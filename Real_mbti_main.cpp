#include <iostream>
#include "Real_mbti_case1.h"
#include "Real_mbti_case2.h"
#include "Real_mbti_case3.h"
using namespace std;

int main()
{
	string answer;
	int insert;

	cout << "*************************************" << endl << endl << endl << endl << endl;
	cout << "            all about MBTI" << endl << endl << endl << endl << endl;
	cout << "*************************************" << endl << endl;
	
	cout << "����� MBTI�� �˰� ��Ű���? Y / N" << endl << endl;
	cin >> answer;
	cout << endl;

	if (answer == "Y")
	{
	again:
		cout << endl << "������ �˰� �����ʴϱ�?" << endl << endl;
		cout << "case1: MBTI information" << endl << endl;

		cout << "case2: Compatibility" << endl << endl;

		cout << "case3: Couple Matching" << endl << endl;

		cout << "case4: Exit" << endl << endl;
		cout << "Choose 1~4" << endl << endl;
		cin >> insert;
		if (insert == 1) {
			Mbti_Image aMbti_Image;
			aMbti_Image.OutImage2();
			goto again;
		}
		else if (insert == 2) {
			Couplefinder();
			goto again;
			cout << endl << endl;
		}
		else if (insert == 3) {
			C3Readcsv use;
			use.matcher();
			goto again;
			cout << endl << endl;
		}
		else if (insert == 4) {
			exit;
		}
		else {
			cout << "Retry" << endl;
			goto again;
		}
	}
	else
	{
		cout << "�� ����Ʈ���� �׽�Ʈ�ϼ���!" << endl;
		cout << "https://www.16personalities.com/ko" << endl;
	}

	


	////////////////

	//C3Readcsv use;

	//use.matcher();
	// 


	//////////////////////////////


	//Couplefinder();


	//return 0;
}