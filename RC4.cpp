#include <cstdlib> 
#include <cstring> 
#include <string> 
#include <iostream>
using namespace std; 
// kelas berisi method dan variabel algoritma rc4
class RC4{ 
	public:
		RC4();
		void stream_setup(char* key);
		char getStream(); 
		char* rc4Crypt(char* data); 
	private: 
		int S[256];
		int K[256]; 
		int i;  
		int j;  
}; 
// konstruktor
RC4::RC4(){ 
	i = 0;  
	j = 0; 
}
// algoritma rc4 untuk mengubah nilai key
void RC4::stream_setup(char* key){ 
	int key_length = strlen(key); 
	int a = 0; 
	int b = 0; 
	int temp = 0; 
	for (a = 0; a < 255; a++){ 
		S[a] = a; 
		K[a] = (int)key[b];
		b++; 
		if (b > key_length){ 
			b=0;
		}
	}
	for (a = 0; a < 255; a++){ 
		b = (b + S[a] + (int)K[a]) % 256;
		temp = S[a];
		S[a] = S[b]; 
		S[b] = temp; 
	}
}
// mengembalikan nilai byte dari hasil enkripsi/dekripsi
char RC4::getStream(){ 
	int temp = 0; 
	i = (i + 1) % 256; 
	j = (j + S[i]) % 256; 
	temp = S[i];
	S[i] = S[j]; 
	S[j] = temp; 
	int t = (S[i] + S[j]) % 256; 
	char* stream = (char *)(&S[t]); 
	return stream[0]; 
}
// mengambil data, xor dengan kunci yang sudah dirandom RC4
char* RC4::rc4Crypt(char* data){ 
	char crypto; 
	int data_length = strlen(data); 
	for (int index = 0; index <= data_length; index++){ 
		crypto = getStream(); 
		data[index] = data[index] ^ crypto; 
	}
	return data; 
}
int main(void){
	cout << "===============================================================\n"; 
	cout << "|          Algoritma RC4 untuk Enkripsi dan Dekripsi          |\n"; 
	cout << "===============================================================\n";
	cout << "|                    Hendy - 20170801143                      |\n"; 
	cout << "|             Hasna Maulida Fajri - 20170801233               |\n"; 
	cout << "|                Angga Puryanto - 20170801203                 |\n"; 
	cout << "|               M. Daffa Hazadin - 20170801093                |\n"; 
	cout << "|        Nadia Dwi Cahya Lestary Kosasih - 20170801013        |\n";
	cout << "===============================================================\n"; 
	system("PAUSE");
	system("CLS");
	char key[100],data[100];
	cout<<"Masukan teks yang ingin dienkripsi/dekripsi:"<<endl;
	cin.getline(data,100);
	cout<<"Masukan kunci:"<<endl;
	cin.getline(key,100);
	RC4 encrypt; 
	
	encrypt.stream_setup(key); 
	cout << "Data asli adalah "<< data << "\n";
	char* data_encrypted = encrypt.rc4Crypt(data); 
	cout << "Hasil enkripsi/dekripsi adalah "; 
	int max = strlen(data); 
	for (int loop = 0; loop <= max; loop++){ 
		cout << data_encrypted[loop]; 
	}
	cout << "\n";
}
