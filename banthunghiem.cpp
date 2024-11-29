#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

string trave(string s){
    stringstream ss(s);
    string day, month, year;
    
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year);

    if (day.size() == 1) day = "0" + day;
    if (month.size() == 1) month = "0" + month;

    return day + month + year;
}

class Available {
protected:
    string DayofWeek[7], shift1, shift2; 
    int NoD;

public:
    void whenAvailable() {
        cout << "Enter no. of available days 1-7: " << endl;
        cin >> NoD;

        while ((NoD < 1) || (NoD > 7)) {
            cout << "Error, the number you entered is out of range." << endl;
            cout << "Enter the number 1-7" << endl;
            cin >> NoD;
        }

        cout << "Enter " << NoD << " days of week for Dr. Available?: " << endl;
        for (int i = 0; i < NoD; i++) {
            cin >> DayofWeek[i];
        }

        cout << "Enter Dr.First Begin: " << endl;
        cin >> shift1;
        cout << "Enter Dr.Second Finish: " << endl;
        cin >> shift2;
    }

    string onlAvailable() {
    	
    	time_t now=time(0);
        struct tm *local = localtime(&now);
   
    
        int jack=local->tm_wday;
        string temp;
    
        switch(jack){
    	    case 0:
    		    temp="sunday";
    		break;
    	    case 1:
    		    temp="monday";
    		    break;
    	    case 2:
    		    temp="tuesday";
    		    break;
    	     case 3:
    		    temp="wednesday";
    		    break;
    	    case 4:
    		    temp="thursday";
    		    break;
    	    case 5:
    		    temp="friday";
    		    break;
    	    case 6:
    		    temp="saturday";
    		    break;
	   }
	    stringstream ss;
        ss << temp << ' '
            << setfill('0') << setw(2) << local->tm_hour
            << setfill('0') << setw(2) << local->tm_min;

        return ss.str();
    }
};

class Disease {
protected:
    string diseasename, virusname;
public:
    void getDiseaseDetail() {
        cout << "Enter the name of disease: ";
        
        getline(cin, diseasename);

        cout << "Enter the name of virus: ";
        getline(cin, virusname);
    }
};

class Person {
protected:
    int age;
    string name, address, phone, date, CCCD, sex;

public:
    void getPersonData() {
        
        cin.ignore();

        cout << "Enter phone: ";
        getline(cin, phone);

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter address: ";
        getline(cin, address);
        
        cout<< "Enter date: ";
        getline(cin, date);
        
        cout<< "Enter CCCD: ";
        getline(cin, CCCD);
        
        cout<< "Enter sex: ";
        getline(cin, sex);
        
        vector<string> v;
	    stringstream ss(date);
	    string token;
	    while(getline(ss,token,'/')) v.push_back(token);
	    age =2024- stoi(v[v.size()-1]);
        
    }
};
class patient : public Person, public Disease {
protected:
    long long patientId;
    long long BHYT;
    string weight;
    string appointDate;

public:
    virtual void getPatientInformation() = 0;  
    virtual void addPatient() = 0;     
    virtual void showPatientDataFromFile() = 0;  
    virtual void editPatient() = 0;
	virtual void xuatinfor()=0;            
    virtual void patienchoice() = 0;
};

class Inpatient : public patient {
private:
    string xuatvien;  // S? ngày n?m vi?n
    string roomNumber;         // S? phòng n?i trú
    char* patientFile = "inpatient.txt";
    char* patientTempFile = "haodzcutohihi.txt";
public:
    void getPatientInformation() override {
        cout << "Enter patient ID: ";
        cin >> patientId;
        
        cout << "Enter BHYT: ";
        cin >> BHYT;
        
        cout << "Enter data of patient: " << endl;
        getPersonData();

        cout << "Enter weight: ";
        getline(cin, weight);

        cout << "Enter disease details: " << endl;
        getDiseaseDetail();

        cout << "Enter appointment date: ";
        getline(cin, appointDate);

        cout << "Enter day xuatvien: ";
        getline(cin,xuatvien);

        cout << "Enter room number: ";
        getline(cin, roomNumber);
    }

    void addPatient() override {
        getPatientInformation();
        
        ofstream patientDatabase(patientFile, ios::app);
        patientDatabase << patientId << endl;
        patientDatabase << BHYT << endl;
        patientDatabase << age << endl;
        patientDatabase << phone << endl;
        patientDatabase << name << endl;
        patientDatabase << address << endl;
        patientDatabase << date << endl;
        patientDatabase << CCCD << endl;
        patientDatabase << sex << endl;
        patientDatabase << weight << endl;
        patientDatabase << diseasename << endl;
        patientDatabase << virusname << endl;
        patientDatabase << appointDate << endl;
        patientDatabase << xuatvien << endl;
        patientDatabase << roomNumber << endl;
        patientDatabase.close();
    }

    void showPatientDataFromFile() override {
        ifstream readdatafromdatabase(patientFile);

        if (!readdatafromdatabase) {
            cout << "Không the mo file." << endl;
            return;
        }
        
        readdatafromdatabase.seekg(0, ios::end);
        if (readdatafromdatabase.tellg() == 0) {
		    cout << "File tr?ng." << endl;
			readdatafromdatabase.close();
        return;
        }
        
        readdatafromdatabase.seekg(0, ios::beg);

        cout << left << setw(5) << "STT" << setw(8) << "patiId" << setw(12) << "BHYT"
             << setw(4) << "age" << setw(13) << "phone" << setw(19) << "name" << setw(15) << "address" 
              << setw(11) << "date" << setw(13) << "CCCD" << setw(6) << "sex" << setw(4) <<"wei"
             << setw(10) << "disease" << setw(9) << "Virus" << setw(11) << "appodate" <<setw(11) <<"xuatvien" <<setw(5)<<"room"<<endl;
        cout << string(156, '=') << endl;
        int count=1;

        // Read and display patient data
         while (readdatafromdatabase >> patientId) {
        	readdatafromdatabase >> BHYT;
            readdatafromdatabase >> age;
            readdatafromdatabase.ignore(); 
            getline(readdatafromdatabase, phone);
            getline(readdatafromdatabase, name);
            getline(readdatafromdatabase, address);
            getline(readdatafromdatabase, date);
            getline(readdatafromdatabase, CCCD);
            getline(readdatafromdatabase, sex);
            getline(readdatafromdatabase, weight);
            
            getline(readdatafromdatabase, diseasename);
            getline(readdatafromdatabase, virusname);
            getline(readdatafromdatabase, appointDate);
            
            
            getline(readdatafromdatabase, xuatvien);
            getline(readdatafromdatabase, roomNumber);

            cout << left << setw(5) << string(4-to_string(count++).length(),'0') + to_string(count) << setw(8) << patientId << setw(12) << BHYT
                 << setw(4) << age << setw(13) << phone << setw(19) << name << setw(15) << address
                  << setw(11) << date << setw(13) << CCCD 
                 << setw(6) << sex << setw(4) <<weight << setw(10) << diseasename << setw(9) << virusname 
                 << setw(11) << appointDate <<setw(11)<<xuatvien<<setw(5)<<roomNumber<< endl<<endl;
        }

        readdatafromdatabase.close();
    }

    void dischargePatient() {
        int n, check = 0;
        cout << "\nNhap mã benh nhân can xóa: " << endl;
        cin >> n;

        ifstream ifpatient(patientFile);
        ofstream ofpatient(patientTempFile);

        while (ifpatient >> patientId) {
        	ifpatient >> BHYT;
            ifpatient >> age;
            ifpatient.ignore();
            getline(ifpatient, phone);
            getline(ifpatient, name);
            getline(ifpatient, address);
            getline(ifpatient, date);
            getline(ifpatient, CCCD);
            getline(ifpatient, sex);
            getline(ifpatient, weight);
            
            getline(ifpatient, diseasename);
            getline(ifpatient, virusname);
            getline(ifpatient, appointDate);
            getline(ifpatient, xuatvien);
            getline(ifpatient, roomNumber);

            if (n == patientId) {
                check = 1;
            } else {
                ofpatient << patientId << endl;
                ofpatient << BHYT << endl;
                ofpatient << age << endl;
                ofpatient << phone << endl;
                ofpatient << name << endl;
                ofpatient << address << endl;
                ofpatient << date << endl;
                ofpatient << CCCD << endl;
                ofpatient << sex << endl;
                ofpatient << weight << endl;
                
                ofpatient << diseasename << endl;
                ofpatient << virusname << endl;
                ofpatient << appointDate << endl;
                ofpatient << xuatvien << endl;
                ofpatient << roomNumber << endl;
            }
        }

        ifpatient.close();
        ofpatient.close();
        remove(patientFile);
        rename(patientTempFile, patientFile);

        if (check == 1) {
            cout << "\nÐã xóa thành công\n";
        } else {
            cout << "\nKhông tìm thay ho so\n";
        }
    }

    void editPatient() {
    int n, check = 0;
    cout << "\nNhap mã benh nhân can chinh sua: " << endl;
    cin >> n;

    ifstream ifpatient(patientFile);
    ofstream ofpatient(patientTempFile);

    while (ifpatient >> patientId) {
        ifpatient >> BHYT;
        ifpatient >> age;
        ifpatient.ignore();
        getline(ifpatient, phone);
        getline(ifpatient, name);
        getline(ifpatient, address);
        getline(ifpatient, date);
        getline(ifpatient, CCCD);
        getline(ifpatient, sex);
        getline(ifpatient, weight);
        
        getline(ifpatient, diseasename);
        getline(ifpatient, virusname);
        getline(ifpatient, appointDate);
        getline(ifpatient, xuatvien);
        getline(ifpatient, roomNumber);

        if (n == patientId) {
            check = 1;
            cout << "\nChinh sua du lieu cua benh nhân có mã so " << n << endl;
            getPatientInformation();
            ofpatient << patientId << endl;
            ofpatient << BHYT << endl;
            ofpatient << age << endl;
            ofpatient << phone << endl;
            ofpatient << name << endl;
            ofpatient << address << endl;
            ofpatient << date << endl;
            ofpatient << CCCD << endl;
            ofpatient << sex << endl;
            ofpatient << weight << endl;
            
            ofpatient << diseasename << endl;
            ofpatient << virusname << endl;
            ofpatient << appointDate << endl;
            
            ofpatient << xuatvien << endl;
            ofpatient << roomNumber << endl;
        } else {
            ofpatient << patientId << endl;
            ofpatient << BHYT << endl;
            ofpatient << age << endl;
            ofpatient << phone << endl;
            ofpatient << name << endl;
            ofpatient << address << endl;
            ofpatient << date << endl;
            ofpatient << CCCD << endl;
            ofpatient << sex << endl;
            ofpatient << weight << endl;
            
            ofpatient << diseasename << endl;
            ofpatient << virusname << endl;
            ofpatient << appointDate << endl;
            
            ofpatient << xuatvien << endl;
            ofpatient << roomNumber << endl;
        }
    }

    ifpatient.close();
    ofpatient.close();
    remove(patientFile);
    rename(patientTempFile, patientFile);

    if (check == 1) {
        cout << "\nDu lieu dã duoc cap nhat thành công\n";
    } else {
        cout << "\nKhông tìm thay ho so\n";
    }
    }
    
    void xuatinfor(){
    	cout<<"Nhap ngay : ";
    	string ngay;
    	cin>>ngay;
    	
    	string day;
    	day=trave(ngay);
    	
    	vector<vector<string>> vec;
    	vector<string> vstr;
    	int check=0;
    	string tmp;
    	
    	ifstream ifpatient(patientFile);
    	
    	while (ifpatient >> patientId) {
        	ifpatient >> BHYT;
            ifpatient >> age;
            ifpatient.ignore();
            getline(ifpatient, phone);
            getline(ifpatient, name);
            getline(ifpatient, address);
            getline(ifpatient, date);
            getline(ifpatient, CCCD);
            getline(ifpatient, sex);
            getline(ifpatient, weight);
            
            getline(ifpatient, diseasename);
            getline(ifpatient, virusname);
            getline(ifpatient, appointDate);
            getline(ifpatient, xuatvien);
            getline(ifpatient, roomNumber);
            
            tmp=trave(appointDate);
            if(day<=tmp){
            	check=1;
            	vstr.push_back(to_string(patientId)),vstr.push_back(to_string(BHYT)),vstr.push_back(to_string(age)),
				vstr.push_back(phone),vstr.push_back(name),vstr.push_back(address),vstr.push_back(date),vstr.push_back(CCCD),
				vstr.push_back(sex),vstr.push_back(weight),vstr.push_back(diseasename),vstr.push_back(virusname),
				vstr.push_back(appointDate),vstr.push_back(xuatvien),vstr.push_back(roomNumber);
				vec.push_back(vstr);
				vstr.clear();
			}
        }
        
        if(check){
        	cout<<"thong tin benh nhan nhap vien tu ngay :"<< ngay << endl;
        	cout << left << setw(5) << "STT" << setw(8) << "patiId" << setw(12) << "BHYT"
             << setw(4) << "age" << setw(13) << "phone" << setw(19) << "name" << setw(15) << "address" 
              << setw(11) << "date" << setw(13) << "CCCD" << setw(6) << "sex" << setw(4) <<"wei"
             << setw(10) << "disease" << setw(9) << "Virus" << setw(11) << "appodate" <<setw(11) <<"xuatvien" <<setw(5)<<"room"<<endl;
            cout << string(156, '=') << endl;
            int count=1;
            
            for(int i=0;i<vec.size();i++){
            	cout<<left<<setw(5)<<string(4-to_string(count++).length(),'0')+to_string(count)<< setw(8) <<vec[i][0] << setw(12) <<vec[i][1]
                 << setw(4) <<vec[i][2]<< setw(13) <<vec[i][3]<< setw(19) <<vec[i][4]<< setw(15) <<vec[i][5]
                  << setw(11) <<vec[i][6]<< setw(13) <<vec[i][7]
                 << setw(6) <<vec[i][8]<< setw(4) <<vec[i][9] << setw(10) << vec[i][10] << setw(9) <<vec[i][11]
                 << setw(11) << vec[i][12] <<setw(11)<<vec[i][13]<<setw(5)<<vec[i][14]<< endl<<endl;
			}
		}
		else{
			cout<<"Khong co benh nhan nao nhap vien tu ngay : "<<ngay<<endl;
		}
        
        
	}
    
    void patienchoice(){
    	char check;
			int choice;
			do {
				cout << "Enter option 1 to add patient" << endl;
				cout << "Enter option 2 to show all data" << endl;
				cout << "Enter option 3 to discharge patient" << endl;
				cout << "Enter option 4 to edit patient's'" << endl;
				cout << "Enter option 5 to print nhap tu ngay"<<endl;
				cout << "Enter option 6 to exit program " << endl;
				cin >> choice;
				cin.ignore(1);
				if (choice == 1) {
					do {
						addPatient();
						cout << "Add another patient? 1 for yes: ";
						cin >> check;
					} while (check == '1');
				}
				else if (choice == 2) {
					showPatientDataFromFile();
				}
				else if (choice == 3) {
					dischargePatient();
				}
				else if (choice == 4) {
					editPatient();
				}else if(choice ==5){
				    xuatinfor();	
				}
			} while (choice == 1 || choice == 2 || choice == 3 || choice == 4||choice==5);
	}
	
};

class Outpatient : public patient {
private:
    string numberOfFollowUps;      // S? l?n tái khám
    string daysBetweenVisits;         // S? phòng n?i trú
    char* patientFile = "outpatient.txt";
    char* patientTempFile = "haodzcutohihi.txt";
public:
    void getPatientInformation() override {
        cout << "Enter patient ID: ";
        cin >> patientId;
        
        cout << "Enter BHYT: ";
        cin >> BHYT;
        
        cout << "Enter data of patient: " << endl;
        getPersonData();

        cout << "Enter weight: ";
        getline(cin, weight);

        cout << "Enter disease details: " << endl;
        getDiseaseDetail();

        cout << "Enter appointment date: ";
        getline(cin, appointDate);

        cout << "Enter so lan tai kham: ";
        getline(cin,numberOfFollowUps);

        cout << "Enter ngay hen dinh ky: ";
        getline(cin, daysBetweenVisits);
    }

    void addPatient() override {
        getPatientInformation();
        
        ofstream patientDatabase(patientFile, ios::app);
        patientDatabase << patientId << endl;
        patientDatabase << BHYT << endl;
        patientDatabase << age << endl;
        patientDatabase << phone << endl;
        patientDatabase << name << endl;
        patientDatabase << address << endl;
        patientDatabase << date << endl;
        patientDatabase << CCCD << endl;
        patientDatabase << sex << endl;
        patientDatabase << weight << endl;
        patientDatabase << diseasename << endl;
        patientDatabase << virusname << endl;
        patientDatabase << appointDate << endl;
        patientDatabase << numberOfFollowUps << endl;
        patientDatabase << daysBetweenVisits << endl;
        patientDatabase.close();
    }

    void showPatientDataFromFile() override {
        ifstream readdatafromdatabase(patientFile);

        if (!readdatafromdatabase) {
            cout << "Không the mo file." << endl;
            return;
        }
        
        readdatafromdatabase.seekg(0, ios::end);
        if (readdatafromdatabase.tellg() == 0) {
		    cout << "File tr?ng." << endl;
			readdatafromdatabase.close();
        return;
        }
        
        readdatafromdatabase.seekg(0, ios::beg);

        cout << left << setw(5) << "STT" << setw(8) << "patiId" << setw(12) << "BHYT"
             << setw(4) << "age" << setw(13) << "phone" << setw(19) << "name" << setw(15) << "address" 
              << setw(11) << "date" << setw(13) << "CCCD" << setw(6) << "sex" << setw(4) <<"wei"
             << setw(10) << "disease" << setw(9) << "Virus" << setw(11) << "appodate" <<setw(9) <<"follows" <<setw(7)<<"between"<<endl;
        cout << string(156, '=') << endl;
        int count=1;

        // Read and display patient data
         while (readdatafromdatabase >> patientId) {
        	readdatafromdatabase >> BHYT;
            readdatafromdatabase >> age;
            readdatafromdatabase.ignore(); 
            getline(readdatafromdatabase, phone);
            getline(readdatafromdatabase, name);
            getline(readdatafromdatabase, address);
//            getline(readdatafromdatabase, email);
            getline(readdatafromdatabase, date);
            getline(readdatafromdatabase, CCCD);
            getline(readdatafromdatabase, sex);
            getline(readdatafromdatabase, weight);
            
            getline(readdatafromdatabase, diseasename);
            getline(readdatafromdatabase, virusname);
            getline(readdatafromdatabase, appointDate);
            
            
            getline(readdatafromdatabase, numberOfFollowUps);
            getline(readdatafromdatabase, daysBetweenVisits);

            cout << left << setw(5) << string(4-to_string(count++).length(),'0') + to_string(count) << setw(8) << patientId << setw(12) << BHYT
                 << setw(4) << age << setw(13) << phone << setw(19) << name << setw(15) << address
                  << setw(11) << date << setw(13) << CCCD 
                 << setw(6) << sex << setw(4) <<weight << setw(10) << diseasename << setw(9) << virusname 
                 << setw(11) << appointDate <<setw(9)<<numberOfFollowUps<<setw(7)<<daysBetweenVisits<< endl<<endl;
        }

        readdatafromdatabase.close();
    }

    void dischargePatient() {
        int n, check = 0;
        cout << "\nNhap mã benh nhân can xóa: " << endl;
        cin >> n;

        ifstream ifpatient(patientFile);
        ofstream ofpatient(patientTempFile);

        while (ifpatient >> patientId) {
        	ifpatient >> BHYT;
            ifpatient >> age;
            ifpatient.ignore();
            getline(ifpatient, phone);
            getline(ifpatient, name);
            getline(ifpatient, address);
        //    getline(ifpatient, email);
            getline(ifpatient, date);
            getline(ifpatient, CCCD);
            getline(ifpatient, sex);
            getline(ifpatient, weight);
            
            getline(ifpatient, diseasename);
            getline(ifpatient, virusname);
            getline(ifpatient, appointDate);
            getline(ifpatient, numberOfFollowUps);
            getline(ifpatient, daysBetweenVisits);

            if (n == patientId) {
                check = 1;
            } else {
                ofpatient << patientId << endl;
                ofpatient << BHYT << endl;
                ofpatient << age << endl;
                ofpatient << phone << endl;
                ofpatient << name << endl;
                ofpatient << address << endl;
//                ofpatient << email << endl;
                ofpatient << date << endl;
                ofpatient << CCCD << endl;
                ofpatient << sex << endl;
                ofpatient << weight << endl;
                
                ofpatient << diseasename << endl;
                ofpatient << virusname << endl;
                ofpatient << appointDate << endl;
                ofpatient << numberOfFollowUps << endl;
                ofpatient << daysBetweenVisits << endl;
            }
        }

        ifpatient.close();
        ofpatient.close();
        remove(patientFile);
        rename(patientTempFile, patientFile);

        if (check == 1) {
            cout << "\nÐã xóa thành công\n";
        } else {
            cout << "\nKhông tìm thay ho so\n";
        }
    }

    void editPatient() {
    int n, check = 0;
    cout << "\nNhap mã benh nhân can chinh sua: " << endl;
    cin >> n;

    ifstream ifpatient(patientFile);
    ofstream ofpatient(patientTempFile);

    while (ifpatient >> patientId) {
        ifpatient >> BHYT;
        ifpatient >> age;
        ifpatient.ignore();
        getline(ifpatient, phone);
        getline(ifpatient, name);
        getline(ifpatient, address);
//        getline(ifpatient, email);
        getline(ifpatient, date);
        getline(ifpatient, CCCD);
        getline(ifpatient, sex);
        getline(ifpatient, weight);
        
        getline(ifpatient, diseasename);
        getline(ifpatient, virusname);
        getline(ifpatient, appointDate);
        getline(ifpatient, numberOfFollowUps);
        getline(ifpatient, daysBetweenVisits);

        if (n == patientId) {
            check = 1;
            cout << "\nChinh sua du lieu cua benh nhân có mã so " << n << endl;
            getPatientInformation();
            ofpatient << patientId << endl;
            ofpatient << BHYT << endl;
            ofpatient << age << endl;
            ofpatient << phone << endl;
            ofpatient << name << endl;
            ofpatient << address << endl;
//            ofpatient << email << endl;
            ofpatient << date << endl;
            ofpatient << CCCD << endl;
            ofpatient << sex << endl;
            ofpatient << weight << endl;
            
            ofpatient << diseasename << endl;
            ofpatient << virusname << endl;
            ofpatient << appointDate << endl;
            
            ofpatient << numberOfFollowUps << endl;
            ofpatient << daysBetweenVisits << endl;
        } else {
            ofpatient << patientId << endl;
            ofpatient << BHYT << endl;
            ofpatient << age << endl;
            ofpatient << phone << endl;
            ofpatient << name << endl;
            ofpatient << address << endl;
//            ofpatient << email << endl;
            ofpatient << date << endl;
            ofpatient << CCCD << endl;
            ofpatient << sex << endl;
            ofpatient << weight << endl;
            
            ofpatient << diseasename << endl;
            ofpatient << virusname << endl;
            ofpatient << appointDate << endl;
            
            ofpatient << numberOfFollowUps << endl;
            ofpatient << daysBetweenVisits << endl;
        }
    }

    ifpatient.close();
    ofpatient.close();
    remove(patientFile);
    rename(patientTempFile, patientFile);

    if (check == 1) {
        cout << "\nDu lieu dã duoc cap nhat thành công\n";
    } else {
        cout << "\nKhông tìm thay ho so\n";
    }
    }
    
    void xuatinfor(){
    	cout<<"Nhap ngay : ";
    	string ngay;
    	cin>>ngay;
    	
    	string day;
    	day=trave(ngay);
    	
    	vector<vector<string>> vec;
    	vector<string> vstr;
    	int check=0;
    	string tmp;
    	
    	ifstream ifpatient(patientFile);
    	
    	while (ifpatient >> patientId) {
        	ifpatient >> BHYT;
            ifpatient >> age;
            ifpatient.ignore();
            getline(ifpatient, phone);
            getline(ifpatient, name);
            getline(ifpatient, address);
            getline(ifpatient, date);
            getline(ifpatient, CCCD);
            getline(ifpatient, sex);
            getline(ifpatient, weight);
                 
            getline(ifpatient, diseasename);
            getline(ifpatient, virusname);
            getline(ifpatient, appointDate);
            getline(ifpatient, numberOfFollowUps);
            getline(ifpatient, daysBetweenVisits);
            tmp=trave(appointDate);
            if(day<=tmp){
            	check=1;
            	vstr.push_back(to_string(patientId)),vstr.push_back(to_string(BHYT)),vstr.push_back(to_string(age)),
				vstr.push_back(phone),vstr.push_back(name),vstr.push_back(address),vstr.push_back(date),vstr.push_back(CCCD),
				vstr.push_back(sex),vstr.push_back(weight),vstr.push_back(diseasename),vstr.push_back(virusname),
				vstr.push_back(appointDate),vstr.push_back(numberOfFollowUps),vstr.push_back(daysBetweenVisits);
				vec.push_back(vstr);
				vstr.clear();
			}
        }
        
        if(check){
        	cout<<"thong tin benh nhan nhap vien tu ngay :"<< ngay << endl;
        	
        	cout << left << setw(5) << "STT" << setw(8) << "patiId" << setw(12) << "BHYT"
             << setw(4) << "age" << setw(13) << "phone" << setw(19) << "name" << setw(15) << "address" 
              << setw(11) << "date" << setw(13) << "CCCD" << setw(6) << "sex" << setw(4) <<"wei"
             << setw(10) << "disease" << setw(9) << "Virus" << setw(11) << "appodate" <<setw(9) <<"follows" <<setw(7)<<"between"<<endl;
             cout << string(156, '=') << endl;
            int count=1;
            
            for(int i=0;i<vec.size();i++){
            	cout<<left<<setw(5)<<string(4-to_string(count++).length(),'0')+to_string(count)<< setw(8) <<vec[i][0] << setw(12) <<vec[i][1]
                 << setw(4) <<vec[i][2]<< setw(13) <<vec[i][3]<< setw(19) <<vec[i][4]<< setw(15) <<vec[i][5]
                  << setw(11) <<vec[i][6]<< setw(13) <<vec[i][7]
                 << setw(6) <<vec[i][8]<< setw(4) <<vec[i][9] << setw(10) << vec[i][10] << setw(9) <<vec[i][11]
                 << setw(11) << vec[i][12] <<setw(9)<<vec[i][13]<<setw(7)<<vec[i][14]<< endl<<endl;
			}
		}
		else{
			cout<<"Khong co benh nhan nao nhap vien tu ngay : "<<ngay<<endl;
		}
        
        
	}
    
    void patienchoice(){
    	char check;
			int choice;
			do {
				cout << "Enter option 1 to add patient" << endl;
				cout << "Enter option 2 to show all data" << endl;
				cout << "Enter option 3 to discharge patient" << endl;
				cout << "Enter option 4 to edit patient's'" << endl;
				cout << "Enter option 5 to print nhap tu ngay"<<endl;
				cout << "Enter option 6 to exit program " << endl;
				cin >> choice;
				cin.ignore(1);
				if (choice == 1) {
					do {
						addPatient();
						cout << "Add another patient? 1 for yes: ";
						cin >> check;
					} while (check == '1');
				}
				else if (choice == 2) {
					showPatientDataFromFile();
				}
				else if (choice == 3) {
					dischargePatient();
				}
				else if (choice == 4) {
					editPatient();
				}else if(choice ==5) {
					xuatinfor();
				}
			} while (choice == 1 || choice == 2 || choice == 3 || choice == 4|| choice == 5);
	}
	
};

class doctor: public Person, public Available{
private:
	long long doctorId;
	string khoa;
	string room;
	string email;
	char* doctorFile = "strange.txt";
	char* doctorTempFile = "spiderman.txt";
public:
	void getdoctordata(){
		cout << "Enter doctorId ";
		cin >> doctorId;
			
		cout << "Enter doctor's department ";
		cin >> khoa;
			
		cout << "Enter doctor's room ";
		cin >> room;
			
		cout << "Enter data of doctor "<<endl;
		getPersonData();
		
		cout << "Enter email: ";
        getline(cin, email);
			
		whenAvailable();
	}
		
	
		
		
	void addDoctorData(){
		getdoctordata();
		
		ofstream doctorDatabase(doctorFile,ios::app);
        doctorDatabase << doctorId << endl;
        doctorDatabase << khoa << endl;
        doctorDatabase << room << endl;
        doctorDatabase << age << endl;
        doctorDatabase << phone << endl;
        doctorDatabase << name << endl;
        doctorDatabase << address << endl;
        doctorDatabase << date << endl;
        doctorDatabase << CCCD << endl;
        doctorDatabase << sex << endl;
        doctorDatabase << email << endl;
        
        doctorDatabase << NoD << endl;
        for (int i = 0; i < NoD ; ++i) 
        doctorDatabase << DayofWeek[i] << endl;
        
        doctorDatabase << shift1 << endl;
        doctorDatabase << shift2 << endl;
        doctorDatabase.close();			
	}
		
	void showDoctorDataFromFile(){
		ifstream readDataFromDatabase(doctorFile);
			
		if (!readDataFromDatabase) {
            cout << "Không the mo file." << endl;
            return;
        }
       
        
        cout << left << setw(5) << "STT" << setw(8) << "docId" << setw(6) << "KHOA" <<setw(6)<<"ROOM"
             << setw(4) << "age" << setw(13) << "phone" << setw(19) << "name" << setw(15) << "address" 
              << setw(11) << "date" << setw(14) << "CCCD" << setw(6) << "sex" << setw(21) << "Email"
             << setw(18) << "available" << setw(12) << "Ca" <<endl;
        cout << string(156, '=') << endl;
        int count=1;
        while (readDataFromDatabase >> doctorId) {
        	readDataFromDatabase.ignore(); 
        	
        	getline(readDataFromDatabase, khoa);
        	getline(readDataFromDatabase, room);
            readDataFromDatabase >> age;
            
            readDataFromDatabase.ignore();
            
            getline(readDataFromDatabase, phone);
            getline(readDataFromDatabase, name);
            getline(readDataFromDatabase, address);
            getline(readDataFromDatabase, date);
            getline(readDataFromDatabase, CCCD);
            getline(readDataFromDatabase, sex);
            getline(readDataFromDatabase, email);
            
            readDataFromDatabase >> NoD;
            readDataFromDatabase.ignore();
            for (int i = 0; i < NoD; ++i) 
            getline(readDataFromDatabase, DayofWeek[i]);
            
			getline(readDataFromDatabase, shift1);
            getline(readDataFromDatabase, shift2);
            
            cout << left << setw(5) << string(4-to_string(count).length(),'0') + to_string(count++) << setw(8) << doctorId << setw(6) << khoa <<setw(6)<<room
             << setw(4) << age << setw(13) << phone << setw(19) << name << setw(15) << address 
              << setw(11) << date << setw(14) << CCCD << setw(6) << sex << setw(21) << email;
             for (int i = 0; i < NoD; ++i)
             	cout<<setw(6)<<DayofWeek[i]<<' ';
             
             cout<<setw(5) <<shift1<<' '<<setw(5)<<shift2 <<endl;
        }

        readDataFromDatabase.close();
	}
		
	void deletedoctor(){
		int n,check=0;
		cout<<"Enter the doctorid of the doctor you want to delete"<<endl;
		cin>>n;
		
		ifstream ifdoctor(doctorFile);
		ofstream ofdoctor(doctorTempFile);
		
		while (ifdoctor >> doctorId) {
			ifdoctor.ignore();
        	getline(ifdoctor, khoa);
        	getline(ifdoctor, room);
            ifdoctor >> age;
            ifdoctor.ignore();
            getline(ifdoctor, phone);
            getline(ifdoctor, name);
            getline(ifdoctor, address);
            getline(ifdoctor, date);
            getline(ifdoctor, CCCD);
            getline(ifdoctor, sex);
            getline(ifdoctor, email);
            
            ifdoctor >> NoD;
            ifdoctor.ignore();
            
            for (int i = 0; i < NoD; ++i) 
            getline(ifdoctor, DayofWeek[i]);
            
            getline(ifdoctor, shift1);
            getline(ifdoctor, shift2);

            if (n == doctorId) {
                check = 1;
            } else {
                ofdoctor << doctorId << endl;
                ofdoctor << khoa << endl;
                ofdoctor << room << endl;
                ofdoctor << age << endl;
                ofdoctor << phone << endl;
                ofdoctor << name << endl;
                ofdoctor << address << endl;
                ofdoctor<< date << endl;
                ofdoctor << CCCD << endl;
                ofdoctor << sex << endl;
                ofdoctor << email << endl;
                
                
                ofdoctor << NoD<< endl;
                for (int i = 0; i < NoD; ++i) 
                    ofdoctor << DayofWeek[i] << endl;
                
                ofdoctor << shift1 << endl;
                ofdoctor << shift2 << endl;
            }
        }
        
	ifdoctor.close();
	ofdoctor.close();
	remove(doctorFile);
	rename(doctorTempFile,doctorFile);
		
	if(check==1) cout<<"\nRecord successfully delete \n";
		
	else
		cout<<"\nRecord not found\n";
	}
		
	void editDoctor() {
		int n, check = 0;
		cout << "\nEnter the doctorid of the doctor you want to edit: " << endl;
		cin >> n;
			
		ifstream ifdoctor(doctorFile);
		ofstream ofdoctor(doctorTempFile);
		
		while (ifdoctor >> doctorId) {
            ifdoctor.ignore(); 
        	
        	getline(ifdoctor, khoa);
        	getline(ifdoctor, room);
            ifdoctor >> age;
            ifdoctor.ignore();
            getline(ifdoctor, phone);
            getline(ifdoctor, name);
            getline(ifdoctor, address);
            getline(ifdoctor, date);
            getline(ifdoctor, CCCD);
            getline(ifdoctor, sex);
            getline(ifdoctor, email);
            
            ifdoctor >> NoD;
            ifdoctor.ignore();
            
            for (int i = 0; i < NoD; ++i) 
            getline(ifdoctor, DayofWeek[i]);
            
            getline(ifdoctor, shift1);
            getline(ifdoctor, shift2);

            if (n == doctorId) {
                check = 1;
                cout << "\nChinh sua du lieu cua benh nhân có mã so " << n << endl;
                getdoctordata();
                ofdoctor << doctorId <<endl;
                ofdoctor << khoa << endl;
                ofdoctor << room << endl;
                ofdoctor << age << endl;
                ofdoctor << phone << endl;
                ofdoctor << name << endl;
                ofdoctor << address << endl;
                ofdoctor << date << endl;
                ofdoctor << CCCD << endl;
                ofdoctor << sex << endl;
                ofdoctor << email << endl;
                
                ofdoctor << NoD << endl;
                for (int i = 0; i < NoD; ++i) 
                    ofdoctor << DayofWeek[i] << endl;
                
                ofdoctor << shift1 << endl;
                ofdoctor << shift2 << endl;
            }else{
            	ofdoctor << doctorId <<endl;
                ofdoctor << khoa << endl;
                ofdoctor << room << endl;
                ofdoctor << age << endl;
                ofdoctor << phone << endl;
                ofdoctor << name << endl;
                ofdoctor << address << endl;
                
                ofdoctor << date << endl;
                ofdoctor << CCCD << endl;
                ofdoctor << sex << endl;
                ofdoctor << email << endl;
                
                ofdoctor << NoD << endl;
                for (int i = 0; i < NoD; ++i) 
                    ofdoctor << DayofWeek[i] << endl;
                
                ofdoctor << shift1 << endl;
                ofdoctor << shift2 << endl;
            	
			}
        }
        
		
        ifdoctor.close();
        ofdoctor.close();
        remove(doctorFile);
        rename(doctorTempFile,doctorFile);
			
		if (check == 1) {
			cout << "\nRecord successfully modified\n";
		} else {
			cout << "\nRecord not found\n";
		}
	}
	
	void online(){
		string onl=onlAvailable();
		vector<string> v;
		stringstream ss(onl);
		string tmp;//them
		while(ss>>tmp) v.push_back(tmp);
		
		vector<string>token;
		
		
		ifstream ifdoctor(doctorFile);
		while (ifdoctor >> doctorId) {
            ifdoctor.ignore(); 
        	
        	getline(ifdoctor, khoa);
        	getline(ifdoctor, room);
            ifdoctor >> age;
            ifdoctor.ignore();
            getline(ifdoctor, phone);
            getline(ifdoctor, name);
            getline(ifdoctor, address);

            getline(ifdoctor, date);
            getline(ifdoctor, CCCD);
            getline(ifdoctor, sex);
            getline(ifdoctor, email);
            
            ifdoctor >> NoD;
            ifdoctor.ignore();
            
            for (int i = 0; i < NoD; ++i) 
            getline(ifdoctor, DayofWeek[i]);
            
            getline(ifdoctor, shift1);
            getline(ifdoctor, shift2);
            
            for(auto &it:DayofWeek){
            	for(auto &x:it) x=tolower(x);
			}
            int check=0;
            for(int i=0;i < NoD; ++i){
            	if(v[0]==DayofWeek[i]){
            		check=1;
            		break;
				}
			}
			
            
			if(!check){
				stringstream ss;
				string hour, minute;
				stringstream timeStream(shift1);
				getline(timeStream, hour, ':');
                getline(timeStream, minute);
                ss << setfill('0') << setw(2) << hour<< setfill('0') << setw(2) << minute;
                
                stringstream ss2;
                stringstream timeStream2(shift2);
                getline(timeStream2, hour,':');
                getline(timeStream2,minute);
                ss2 << setfill('0') << setw(2) << hour<< setfill('0') << setw(2) << minute;
                
                if(v[1]>=ss.str()&&v[1]<=ss2.str()){
                	token.push_back(name);
				}
			}
			
			
  //  cout << "Result: " << ss.str() << endl;
            
        }
        ifdoctor.close();
        
        for(auto x:token) cout<<x<<endl;
        
	}
		
	void doDoctorRelateWork() {
		char check;
		int choice;
		do {
			cout << "Enter option 1 to add doctor" << endl;
			cout << "Enter option 2 to show all data" << endl;
			cout << "Enter option 3 to delete" << endl;
			cout << "Enter option 4 to edit doctor's'" << endl;
			cout << "Enter option 5 to printf doctor's online "<<endl;
			cout << "Enter option 6 to exit program " << endl;
			cin >> choice;
			cin.ignore(1);
			if (choice == 1) {
				do {
					addDoctorData();
					cout << "Add another doctor? 1 for yes: ";
					cin >> check;
				} while (check == '1');
			}
			else if (choice == 2) {
				showDoctorDataFromFile();
			}
			else if (choice == 3) {
				deletedoctor();
			}
			else if (choice == 4) {
				editDoctor();
			}
			else if(choice == 5){
				online();
			}
		} while (choice == 1 || choice == 2 || choice == 3 || choice == 4||choice == 5);
	} 
};

int main() {
    patient *p=new Outpatient;
    p->patienchoice();

}

