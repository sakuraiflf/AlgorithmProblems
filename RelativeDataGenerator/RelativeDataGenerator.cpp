#include <iostream>
#include <random>
#include <fstream>
#include <string>
using namespace std;

/*
���ݣ����鼯�������������������
*/

int main()
{
	std::random_device r;
	std::default_random_engine e1(r());
	// ���������ݶ��� �ķ�Χ�� [1, 10] ֮��������
	std::uniform_int_distribution<int> total_range(1, 10);

	ofstream outfile("data.txt");
	if (outfile) {

		// �����������
		int people = total_range(e1);
		// ����������ݹ�ϵ����
		int pair = total_range(e1);
		outfile << people << " " << pair << " ";

		// �� [1, ����] ������������ݹ�ϵ
		std::uniform_int_distribution<int> people_range(1, people);

		// ������� pair �Թ�ϵ
		for (size_t i = 0; i < pair; i++)
		{
			int p1 = people_range(e1);
			int p2 = people_range(e1);
			while (p1 == p2)
			{
				p2 = people_range(e1);
			}
			outfile << p1 << " " << p2 << " ";
		}

		// ������ɲ�ѯ�Ĺ�ϵ����
		int relationship = total_range(e1);
		outfile << relationship << " ";

		// ��ѯ relationship �Թ�ϵ
		for (size_t i = 0; i < relationship; i++)
		{
			int r1 = people_range(e1);
			int r2 = people_range(e1);
			while (r1 == r2)
			{
				r2 = people_range(e1);
			}
			outfile << r1 << " " << r2 << " ";
		}

		outfile.close();
	}
	else {
		cerr << "Cannot write data.txt file" << endl;
	}
	return 0;
}