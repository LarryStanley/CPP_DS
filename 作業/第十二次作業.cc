/*
學號:101201033
系級:數學二B
姓名:曾崇軒
第_次作業:12
編譯環境:xcode
聯絡信箱:kill.xmurderer@gmail.com
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void){
	
	//載入資料
	ifstream infile("data");
	
	//宣告各種變數
	string line;
	vector< vector<string> > allData;
	
	//紀錄所有資料並且算出該行平均值
	int lineNumber = 0;
	while (getline(infile, line)){
		istringstream lineStream(line);
		string item;
		int itemNumber = 0;
		vector<string> tempData;
		while (getline (lineStream, item, ',')){
			tempData.push_back(item);
		}
		//計算平均值
		float result = 0;
		for (int i = 1; i < tempData.size(); i++){
			stringstream itemInString(tempData[i]);
			float itemInFloat;
			itemInString >> itemInFloat;
			result = result + itemInFloat;
		}
		result = result/(tempData.size()-1);
		stringstream resultString;
		resultString << result;
		tempData.push_back(resultString.str());

		allData.push_back(tempData);
		lineNumber++;
	}

	//印出結果
	cout << setw(45) << "平均值" << setw(8) << "3 日" << setw(8)  << "5 日" << setw(8) << "7 日" << endl;
	cout << setw(51) << "移動" << setw(11) << "移動" << setw(11) << "移動" << endl;
	cout << setw(53) << "平均值" << setw(11) << "平均值" << setw(11) << "平均值" << endl;
	for (int i = 0; i < allData.size(); i++){
		if (i){
			//印出原資料
			for (int j = 0; j < allData[i].size(); j++){
				if (j){
					cout << setw(8);
					stringstream dataInString(allData[i][j]);
					float printData;
					dataInString >> printData;
					cout << setprecision(4) << printData;
				}else
					cout << allData[i][j];
			}
			//三、五、七日平均
			int day[3] = {3,5,7};
			for (int j = 0; j < 3; j++){
				float result;
				if (allData.size() - i < day[j])
					result = 0;
				else{
					for (int k = 0; k < day[j]; k++){
						stringstream dataInString(allData[i+k][4]);
						float dataInFloat;
						dataInString >> dataInFloat;
						result = result + dataInFloat;
					}
					result = result/day[j];
				}
				cout << setw(8) << setprecision(4) << result;
			}
			cout << endl;
		}
	}

	return 0;
}
