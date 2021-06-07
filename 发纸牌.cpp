#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib> 
using namespace std;

int sign[4][13]={0};
string str1[4]={"梅花","黑桃","红桃","方块"};
string str2[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
int sendcardnum=0;

class playcard{
	public:
		playcard(int name1){
			num=0;
			name=name1;
		}
		~playcard(){
			cout<<"game over" ;
		}
		void sendcards(int n);
		void printcards();
	private:
		string card[30];
		int num;
		int name;
};
void playcard::sendcards(int n){
	int i,j,k;
	num=n;
	//memset(sign,0,n);
	srand (time(NULL
	));
	for(k=0;k<n&&sendcardnum<52;){
		i=rand()%4;
		j=rand()%13;
		if(sign[i][j]==1){
			continue;
		}else{
			card[k]=str1[i]+str2[j];
			sign[i][j]=1;
			k++;
			sendcardnum++;
		}
	}
}
void playcard::printcards(){
	cout<<name<<"的牌是："<<endl ;
	for(int k=0;k<num;k++){
		cout<<card[k]<<"\t";
	}
	cout<<endl; 
}

int main(){
	int n,name1=1;
	playcard p1(name1++),p2(name1++),p3(name1++);
	cout<<"输入发牌数";
	cin>>n;
	p1.sendcards(n);
	p2.sendcards(n);
	p3.sendcards(n);	
	p1.printcards();
	p2.printcards();
	p3.printcards();
	return 0; 
}

