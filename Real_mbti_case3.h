#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

class C3Readcsv {
private:
	vector <string> data; // ��ü ������
	string data_line; // ����

	/// <matcher()�� ����>
	int index;


public:
	vector <string> kosta_name;
	vector <int> kosta_mbti;

	C3Readcsv() {
		ifstream file("DBkosta2.csv");

		while (getline(file, data_line)) {
			istringstream line(data_line); //������ �����̽� (��) 

			string data_one;

			while (getline(line, data_one, ',')) { //������ �����̽� (�߰�)
				data.push_back(data_one); //���Ϳ� �̸�/MBTI������ ���� 
			}
		}

		int i = 0;
		int a = 0;
		for (vector <string>::iterator iter = data.begin(); iter != data.end(); iter++) { //
			if (i % 2 == 0) { //¦���� �̸����� 
				kosta_name.push_back(data.at(i));
			}
			else {
				for (int j = 0; j < 16; j++) {
					if (data.at(i) == personalities[j]) a = j;
				}
				kosta_mbti.push_back(a); //Ȧ���� MBTI��
			}
			i++;
		}
		//for (auto x : kosta_mbti) { cout << x << endl; } //debug
	}


	string name;
	int matcher() {

		jump:
		cout << endl << "�̸��� �Է����ּ���: ";
		cin >> name;
		for (int i = 0; i < name.size(); i++)
		{
			name[i] = toupper(name[i]);

		}

		//�̸��� �׻���� �ش�Ǵ� MBTI ���ڸ� index�� ����
		int z = 0;

		for (vector <string>::iterator iter1 = kosta_name.begin(); iter1 != kosta_name.end(); iter1++) {
			if (name == kosta_name.at(z)) {
				index = kosta_mbti.at(z);
				break;
			}
			else if (iter1 == kosta_name.end() - 1 ) {
				cout << "�̸��� �߸��ƽ��ϴ�, ";
				goto jump;
			}
			z++;
		}

		//kosta_mbti�� loop�ɾ rmatrix�� �ִ� 1���ڸ� ã���� �׼��ݿ� �ش�Ǵ� ����� �̸��� ���

		string YorN;
		cout << "<�ְ��� ����>" << endl;
		if (find_match(1) == 1) {
			return 0;
		}
		else {
			cout << "�ְ��� ������ �� ã�ҽ��ϴ�." << endl;
			cout << "�������� ���� ������ ã���ڽ��ϱ�? (Y/N)" << endl;
			cin >> YorN;
			for (int i = 0; i < YorN.size(); i++)
			{
				YorN[i] = toupper(YorN[i]);

			}
			if (YorN == "Y") {
				cout << "<���� ����>" << endl;
				if (find_match(2) == 1) return 0;
				else cout << "�������� ���� ������ �� ã�ҽ��ϴ�, ȥ�ڼ� �����ϼž߰ڳ׿�" << endl;
			}
		}
	}

	int find_match(int level) {
		int others = 0;
		int TorF = 0;
		for (vector <int>::iterator iter2 = kosta_mbti.begin(); iter2 != kosta_mbti.end(); iter2++) {
			if (couplemat[index][kosta_mbti.at(others)] == level) {
				cout << kosta_name.at(others) << endl;
				TorF = 1;
			}
			others++;
		}
		return TorF;
	}
};