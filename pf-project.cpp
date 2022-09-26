#include<iostream>
using namespace std;

const int row_size = 4, col_size = 6;

void output(double arr[][col_size])
{
	cout << "Note: -1 means Empty Space" << endl;
	for (int i = 0; i < row_size; i++)
	{
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|    Field " << i + 1 << "\t|";
		for (int j = 0; j < col_size; j++)
		{
			cout << "\t" << arr[i][j] << "\t|";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void maxScore(double arr[][col_size])
{
	double sum, max_Score = 0;
	int field;
	for (int i = 0; i < row_size; i++)
	{
		sum = 0;
		for (int j = 0; j < col_size; j++)
		{
			if (arr[i][j] != -1)
			{
				sum += arr[i][j];
			}
		}
		if (max_Score < sum)
		{
			max_Score = sum;
			field = i;
		}
	}
	cout << "Field " << field + 1 << " has the maximum success score." << endl;
}

void avg(double arr[][col_size])
{
	double avg, itr, sum;
	for (int i = 0; i < row_size; i++)
	{
		sum = 0;
		itr = 0;
		for (int j = 0; j < col_size; j++)
		{
			if (arr[i][j] != -1)
			{
				sum += arr[i][j];
				itr++;
			}
		}
		avg = sum / itr;
		cout << "Field " << i + 1 << " average: ";
		if (itr == 0)
		{
			cout << "Empty Field" << endl;
		}
		else
		{
			cout << avg << endl;
		}
	}
}

void frequency(double arr[][col_size])
{
	int count, max_count = 0, second_max_count = 0, itr1, itr2, itr3, itr4;
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (arr[i][j] == -1)
			{
				break;
			}
			count = 0;
			for (int k = 0; k < row_size; k++)
			{
				for (int l = 0; l < col_size; l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						count++;
					}
				}
			}
			if (max_count < count)
			{
				max_count = count;
				itr1 = i;
				itr2 = j;
			}
			else if (second_max_count < count && max_count > count)
			{
				second_max_count = count;
				itr3 = i;
				itr4 = j;
			}
			else if (max_count == count && arr[itr1][itr2] != arr[i][j])  // If both top two values have same number of occurrence
			{
				second_max_count = count;
				itr3 = i;
				itr4 = j;
			}
		}
	}
	cout << arr[itr1][itr2] << " has maximum occurrence of " << max_count << " times." << endl;
	cout << arr[itr3][itr4] << " has maximum occurrence of " << second_max_count << " times." << endl;
}

void deleteValue(double arr[][col_size])
{
	int field, loc;
	cout << "Enter the field in which you want to delete a value: ";
	cin >> field;
	while (field < 1 || field > 4)
	{
		cout << endl << "Invalid Input...\nEnter fields from 1 to 4: ";
		cin >> field;
	}
	cout << "Enter the location in which you want to delete a value: ";
	cin >> loc;
	while (loc < 1 || loc > 6)
	{
		cout << endl << "Invalid Input...\nEnter locations from 1 to 6: ";
		cin >> loc;
	}
	if (arr[field - 1][loc - 1] == -1)
	{
		cout << "Already a Empty space...." << endl;
	}
	else
	{
		arr[field - 1][loc - 1] = -1;
		output(arr);
	}
}

void totalNumber(double arr[][col_size])
{
	int count = 0;
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (arr[i][j] != -1)
			{
				count++;
			}
		}
	}
	cout << "There are " << count << " test score values entered in table." << endl;
}

void insert(double arr[][col_size])
{
	int field, num, i;
	bool flag = true;
	cout << "Enter the field in which you want to enter a value: ";
	cin >> field;
	while (field < 1 || field > 4)
	{
		cout << endl << "Invalid Input...\nEnter fields from 1 to 4: ";
		cin >> field;
	}
	cout << "Enter the value you want to enter: ";
	cin >> num;
	for (i = 0; i < col_size; i++)
	{
		if (arr[field - 1][i] == -1)
		{
			arr[field - 1][i] = num;
			flag = false;
			break;
		}
	}
	output(arr);
	if (flag)
	{
		cout << "No Space Left in field " << field << endl;
	}
	else
	{
		cout << num << " is entered in field " << field << " at location " << i + 1 << endl;
	}
}

void footer()
{
	cout << "              *******  *     *      *      *     *  *   *        *       *   ***   *    *" << endl;
	cout << "                 *     *     *     * *     * *   *  * *            *   *    *   *  *    *" << endl;
	cout << "                 *     * * * *    *   *    *  *  *  **               *      *   *  *    *" << endl;
	cout << "                 *     *     *   * * * *   *   * *  * *              *      *   *  *    *" << endl;
	cout << "                 *     *     *  *       *  *     *  *   *            *       ***    **** " << endl << endl;
}

void header()
{
	cout << "                  ****   *****       ****   ****    ***   *******  *****   *****  *******" << endl;
	cout << "                  *   *  *           *   *  *   *  *   *     *     *      *          *   " << endl;
	cout << "                  ****   *****       ****   ****   *   *     *     ****   *          *   " << endl;
	cout << "                  *      *           *      * *    *   *     *     *      *          *   " << endl;
	cout << "                  *      *           *      *  *    ***   * *      *****   *****     *   " << endl;
	cout << "                                                                               Done By Roman Farooq-L1F20BSCS0338" << endl;
	cout << "\t\t\t\t******************************************" << endl;
	cout << "\t\t\t\t*  PESTCOUTS Research Lab Field Records  * " << endl;
	cout << "\t\t\t\t******************************************" << endl;
}

void menu()
{
	cout << endl << "\t\t\t****************************************************************" << endl;
	cout << "\t\t\t*   Press 1 --> Insert new test result.                        *" << endl;
	cout << "\t\t\t*   Press 2 --> Display total number of results in table.      *" << endl;
	cout << "\t\t\t*   Press 3 --> Delete any test value from table.              *" << endl;
	cout << "\t\t\t*   Press 4 --> Display the 2 most frequent values in table.   *" << endl;
	cout << "\t\t\t*   Press 5 --> Display average scores of each field.          *" << endl;
	cout << "\t\t\t*   Press 6 --> Display field having maximum success score.    *" << endl;
	cout << "\t\t\t*   Press 7 --> View Table.                                    *" << endl;
	cout << "\t\t\t*   Press 8 --> Stop the Programe.                             *" << endl;
	cout << "\t\t\t****************************************************************" << endl;
}

int main()
{
	double arr[row_size][col_size] = { { 5, 1, 21, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1 },
	{ 23, 5, 20, 5, 30, -1 }, { 1, 9, 5, 0, -1, -1 } };
	int option;
	header();
	output(arr);
	do
	{
		menu();
		cout << "Enter your Option ===> ";
		cin >> option;
		while (option < 1 || option > 8)
		{
			cout << endl << "Invalid Input...\nEnter choices from 1 to 8: ";
			cin >> option;
		}
		cout << endl;
		if (option == 1)
		{
			insert(arr);
		}
		else if (option == 2)
		{
			totalNumber(arr);
		}
		else if (option == 3)
		{
			deleteValue(arr);
		}
		else if (option == 4)
		{
			frequency(arr);
		}
		else if (option == 5)
		{
			avg(arr);
		}
		else if (option == 6)
		{
			maxScore(arr);
		}
		else if (option == 7)
		{
			output(arr);
		}
		else if (option == 8)
		{
			footer();
		}
	} while (option != 8);
	return 0;
}
