// slkillboxbot.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

string toLower(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);

	return text;
}

map<string, string> database{
	{"hello", "hello Human"},
	{"what is your name", "I'm SkillBot4000"},
	{"what are you doing", "whitin specified params"},
};

void bot(string msg) {
	cout << "[BOT]" << msg << endl;
}

string user() {
	string question;
	cout << "[USER]: ";
	getline(cin, question);
	question = toLower(question);
	return question;
}

int loadPhrases()
{
	ifstream phrases("database.txt");
	string line;
	int len = 0;
	while (getline(phrases, line)) {
		int pos = line.find('$');
		string question = line.substr(0, pos);
		string answer = line.substr(pos + 1);
		database.insert(pair<string, string>(question, answer));
		len++;
	}
	return len;

}

void savePhrases() {
	//vcpckg
	//dz 
	// more quest answer
	// научить отвечать если нет ответов
}

int main()
{
	int phraseCount = loadPhrases();
	bot("Hello, I'm SkillBot4000, I can answer " + to_string(phraseCount) + " any questions!");

	

	string question;

	while (question != "exit") {
		question = user();

		for (auto entry : database) {
			regex pattern(".*" + entry.first + ".*");
			if (regex_match(question, pattern)) {
				bot(entry.second);
			}
		}
	}


	/*
	if (regex_match(question, hello)) {
		cout << "Hello hooman" << endl;
	}

	regex whatname(".*what is your name.*");

	if (regex_match(question, whatname)) {
		cout << "my name is SkillBot4000" << endl;
	}
	*/
}

