#include "stdafx.h"
#include <iostream>

using namespace std;
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <deque>
#include <numeric>
/*
共有24个人参加, 比赛共三轮。按参赛号顺序分组, 第一轮分4个小组, 第二轮分为个小组; 每组均为6人, 每轮每组淘汰最后3民成员。第三轮为决赛, 只剩6人, 选出前3名。
比赛评分：10个评委打分，去除最低、最高分，求平均分
1）	请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
2）	打印每一轮比赛前，分组情况
3）	打印每一轮比赛后，小组晋级名单
4）	打印决赛前三名，选手名称、成绩。
*/
class Speaker {
public:
	string m_name;
	int m_score[3];
};

int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v) {
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++) {
		Speaker tmp;
		tmp.m_name = "Player_";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));
	}

	for (int i = 0; i < 24; i++) {
		v.push_back(100 + i);
	}
	return 0;
}

int speech_contest_draw(vector<int> &v) {
	random_shuffle(v.begin(), v.end());
	return 0;
}

int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2) {
	//score, iterator, func_obj
	multimap<int, int, greater<int>> multiMapGroup;//group grade
	int tmpCount = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		tmpCount++;

		//打分
		{
			deque<int> dscore;
			for (int j = 0; j < 10; j++) {//10个评委打分
				int score = 50 + rand() % 50;
				dscore.push_back(score);
			}
			sort(dscore.begin(), dscore.end());
			dscore.pop_back();//去掉最高分和最低分
			dscore.pop_front();

			//求平均分
			int scoreSum = accumulate(dscore.begin(), dscore.end(), 0);
			int scoreAvg = scoreSum / dscore.size();
			mapSpeaker[*it].m_score[index] = scoreAvg;//选手得分, 存入容器中
			multiMapGroup.insert(pair<int, int>(scoreAvg, *it));
		}

		//处理分组
		if (tmpCount % 6 == 0) {
			cout << "group :" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multiMapGroup.begin(); mit != multiMapGroup.end(); mit++)
			{
				//id, name, score
				cout << mit->second << ":\t" << mapSpeaker[mit->second].m_name << endl;
			}

			while (multiMapGroup.size() > 3) {
				multimap<int, int, greater<int>>::iterator it = multiMapGroup.begin();
				v2.push_back(it->second);//把前三名 放到v2 的晋级名单中
				multiMapGroup.erase(it);
			}
			multiMapGroup.clear();
		}
	}
	return 0;
}

int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker) {
	printf("round %d, rise list\n",index+1);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "player id:" << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}
	return 0;
}

int main() {
	//container designing
	map<int, Speaker> mapSpeaker;
	vector<int> v1;//player list in round 1
	vector<int> v2;//player list in round 2
	vector<int> v3;//player list in round 3
	vector<int> v4;//player list in final round

	//generator players
	GenSpeaker(mapSpeaker, v1);

	//round 1, draw, contest, result
	cout << "press to start round 1" << endl;
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0, v2, mapSpeaker);

	//round 2, 
	cout << "press to start round 2" << endl;
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);

	//round 3, 
	cout << "press to start round 3" << endl;
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
