//main.cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using namespace std;

int main() {
	vector<Student_info>students;
	Student_info record;
	string::size_type maxlen = 0;

	//������ �а� �����ϱ�
	while (record.read(cin)) {
		maxlen = max(maxlen, record.get_name(), size());
		students.push_back(record);
	}
	//�л� ��� �����ϱ�
	sort(students.begin(), students.end(), compare);

	//�̸��� ���� ����ϱ�
	for (vector<Student_info>::size_type i = 0;
		i != students.size(), i++) {
		cout << students[i].get_name()
			<< string(maxlen + 1
				- students[i].get_name().size(), ' ');

		try {
			double final_grade = students[i].grad();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl; //���� ���
		}
	}
}
