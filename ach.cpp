#include<bits/stdc++.h>
using namespace std;
int system(string s){
	return system(s.data());
}
void init(){
	system("acc config oj-path oj");
	system("acc config default-task-choice all");
	system("acc login");
	system("oj login https://atcoder.jp");
	system("acc config-dir > dir.txt");
	ifstream fin("dir.txt");
	string ss;
	getline(fin,ss);
	fin.close();
	system("del dir.txt");
	string command="mkdir "+ss+"\\template";
	system(command);
	ofstream fout((ss+"\\template\\main.cpp"));
	fout<<"#include<bits/stdc++.h>"<<endl;
	fout<<"using namespace std;"<<endl;
	fout<<"int main(){"<<endl;
	fout<<"    return 0;"<<endl;
	fout<<"}"<<endl;
	fout.close();
	ofstream fout2((ss+"\\template\\template.json"));
	fout2<<"{"<<endl;
	fout2<<"  \"task\": {"<<endl;
	fout2<<"    \"program\": [[\"main.cpp\", \"{TaskLabel}.cpp\"]],"<<endl;
	fout2<<"    \"submit\": \"{TaskLabel}.cpp\","<<endl;
	fout2<<"    \"testdir\": \".\","<<endl;
	fout2<<"    \"cmd\": \"echo Parsed task successfully!\""<<endl;
	fout2<<"  },"<<endl;
	fout2<<"  \"contest\": {"<<endl;
	fout2<<"    \"cmd\": \"echo Parsed contest successfully!\""<<endl;
	fout2<<"  }"<<endl;
	fout2<<"}"<<endl;
	fout2.close();
	system("acc config default-template template");
	cout<<"Current template:"<<endl;
	cout<<"#include<bits/stdc++.h>"<<endl;
	cout<<"using namespace std;"<<endl;
	cout<<"int main(){"<<endl;
	cout<<"    return 0;"<<endl;
	cout<<"}"<<endl;
	cout<<"Current template may not suit your needs.If you want to edit template,please open "<<ss<<"\\template\\main.cpp"<<endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string args[12];
	for(int i=0;i<argc;i++) args[i]=argv[i];
	if(argc>=2&&args[1]=="submit"){
		string cmd="acc submit -s ",str;
		if(argc>=3) cmd+=" --";
		for(int i=2;i<argc;i++){
			str=argv[i];
			cmd+=" ";
			cmd+=str;
		}
		system(cmd.data());
	}
	else if(args[1]=="test"){
		for(int i=1;i<=9;i++){
			string s="0";
			s[0]+=i;
			ifstream fin(("sample-"+s+".in").data());
			if(!fin) break;
			fin.close();
			ifstream fin2(("in"+s+".txt").data());
			if(!fin2) system("copy \"sample-"+s+".in\" \"in"+s+".txt\"");
			fin2.close();
			ifstream fin3(("ans"+s+".txt").data());
			if(!fin3) system("copy \"sample-"+s+".out\" \"ans"+s+".txt\"");
			fin3.close();
		}
		system("cf test");
	}
	else if(argc>=3&&args[1]=="race"){
		system("acc contest "+args[2]);
		system("acc new "+args[2]);
		system("start https://atcoder.jp/contests/"+args[2]+"/tasks_print");
		for(int i=0;i<6;i++){
			string s="A";
			s[0]+=i;
			system(args[2]+"\\"+s+"\\"+s+".cpp");
		}
	}
	else if(argc>=3&&args[1]=="stand")
		system("start https://atcoder.jp/contests/"+args[2]+"/standings");	
	else if(argc>=3&&args[1]=="list")
		system("acc tasks"+args[2]);
	else if(args[1]=="init") init();
	else{
		cout<<"Atcoder Commandline Helper(ach) v1.0"<<endl;
		cout<<"If you've never used this before,please run `ach init`"<<endl;
		cout<<"Usage:"<<endl;
		cout<<"ach submit [OJOPTIONS]:submit a task"<<endl;
		cout<<"ach test:test program under current directory"<<endl;
		cout<<"ach race [CONTESTID]:open a contest,generate templates and open programs"<<endl;
		cout<<"ach stand [CONTESTID]:open standings page"<<endl;
		cout<<"ach list [CONTESTID]:show problem info"<<endl;
		cout<<"ach init:initialize templates and login"<<endl;
	}
	return 0;
}
