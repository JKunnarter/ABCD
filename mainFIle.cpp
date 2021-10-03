#include <iostream>
#include <string.h>

using namespace std;

class TAINGHE {
private:
    string MaTaiNghe;
    string NuocSX;
    int SoLuong;

public: 
    string TenTaiNghe;
    long DonGia;
    long long ThanhTien;
public:
    TAINGHE(string MaTaiNghe, string TenTaiNghe, string NuocSX, long DonGia, int SoLuong) {
        this->MaTaiNghe = MaTaiNghe;
        this->TenTaiNghe = TenTaiNghe;
        this->NuocSX = NuocSX;
        this->DonGia = DonGia;
        this->SoLuong = SoLuong;
        this->ThanhTien = SoLuong * DonGia;
    }


    void display() {
        cout << "\nMa Tai Nghe: " << MaTaiNghe;
        cout << "\nTen Tai Nghe: " << TenTaiNghe;
        cout << "\nNuoc San Xuat: " << NuocSX;
        cout << "\nDon Gia: " << DonGia;
        cout << "\nSo Luong: " << SoLuong;
        cout << "\nThanh Tien: " << ThanhTien;
        cout << endl;
    }
};

class SingleLinkedList {    
private:
    class Node {
        public:
            TAINGHE* TaiNghe;
            Node* next;

            Node(TAINGHE* TaiNghe) { this->TaiNghe = TaiNghe; this->next = NULL; }
            ~Node() {}
    };

    int length;
    Node *head, *tail; 

public:
    SingleLinkedList() {
        head = tail = NULL;
        length = 0;
    }

    void AddNode(TAINGHE* TaiNghe) {
        Node* newNode = new Node(TaiNghe);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void sortList() {
        for (Node* i = head; i->next != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->TaiNghe->DonGia > j->TaiNghe->DonGia) {
                    TAINGHE* temp = i->TaiNghe;
                    i->TaiNghe = j->TaiNghe;
                    j->TaiNghe = temp;
                }
            }
        }
    }
    int sumOf() {
        long long result = 0;
        for (Node* curNode = head; curNode != NULL; curNode = curNode->next) {
            result += curNode->TaiNghe->ThanhTien;
        }
        return result;
    }

    TAINGHE* findX(string TenTaiNghe) {
        for (Node* curNode = head; curNode != NULL; curNode = curNode->next) {
            if (curNode->TaiNghe->TenTaiNghe == TenTaiNghe) return curNode->TaiNghe;
        }
        return NULL;
    }

    void showUpper250K() {
        for (Node* curNode = head; curNode != NULL; curNode = curNode->next) {
            if (curNode->TaiNghe->DonGia > 250000) curNode->TaiNghe->display();
        }
    }

    void showHiggest() {
        Node* higgestNode;
        long curCost = LONG_MIN;
        for (Node* curNode = head; curNode != NULL; curNode = curNode->next) {
            if (curNode->TaiNghe->DonGia > curCost) {
                higgestNode = curNode;
                curCost = curNode->TaiNghe->DonGia;
            }
        }
        higgestNode->TaiNghe->display();
    }
    void display() {
        for (Node* curNode = head; curNode != NULL; curNode = curNode->next) curNode->TaiNghe->display();
    }

};


void getInput(SingleLinkedList& myList) {
    int isFinish;

    string MaTaiNghe;
    string TenTaiNghe; 
    string NuocSX; 

    long DonGia; 
    int SoLuong;

    while (true) {
        cin.ignore();
        cout << "Nhap Ma Tai Nghe: "; getline(cin, MaTaiNghe);
        cout << "Nhap Ten Tai Nghe: "; getline(cin, TenTaiNghe);
        cout << "Nhap Nuoc San Xuat: "; getline(cin, NuocSX); 
        cout << "Nhap Don Gia: "; cin >> DonGia;
        cout << "Nhap So Luong: "; cin >> SoLuong;
        
        myList.AddNode(new TAINGHE(MaTaiNghe, TenTaiNghe, NuocSX, DonGia, SoLuong));

        cout << "Hoan thanh (0), Chua hoan thanh (1)?"; cin >> isFinish;
        cout << endl;
        if (isFinish == 0) break; 
    }
}

int main() {
    int choose;
    bool isInit = false;
    string TenTaiNghe;
    SingleLinkedList myList;

    while (true) {
        cout << "0. Nhap so 0 de khoi tao danh sach.";
        cout << "\n1. Nhap so 1 de nhap du lieu.";
        cout << "\n2. Nhap so 2 de in danh sach.";
        cout << "\n3. Nhap so 3 de tim kiem.";
        cout << "\n4. Nhap so 4 de sap xep.";
        cout << "\n5. Nhap so 5 de tinh tong tien.";
        cout << "\n6. Nhap so 6 de hien thi cac tai nghe co gia > 250.000 dong";
        cout << "\n7. Nhap so 7 de hien thi tai nghe co don gia cao nhat.";
        cout << "\n8. Nhap so 8 de thoat chuong trinh.";
        cout << "\nLua chon cua ban: "; cin >> choose;

        if (choose < 0 || choose > 8 ) {
            cout << "Ban nhap khong hop le! Vui long nhap lai!" << endl;
            continue; 
        }
        if (choose == 8) { cout << "Chuong trinh dang ket thuc!" << endl; break; }
        system("cls");

        switch (choose) {
        case 0:
            if (isInit) { cout << "Ban da khoi tao danh sach roi!" << endl; } 
            else { cout << "Khoi tao danh sach thanh cong!" << endl; isInit = true; }
            break;
        case 1:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else getInput(myList);
            break;
        case 2:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else myList.display();
            break;
        case 3:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else { 
                cout << "Nhap ten tai nghe: "; cin.ignore(); getline(cin, TenTaiNghe); 
                TAINGHE* find = myList.findX(TenTaiNghe);
                if (find) {
                    find->display();
                } else {
                    cout << "Khong ton tai tai nghe co ten " << TenTaiNghe << endl;
                }   
                
            }
            break;
        case 4:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else { myList.sortList(); cout << "Da sap xep danh sach thanh cong!" << endl; }
            break;
        case 5: 
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else { cout << "Tong tien: " << myList.sumOf() << endl; }
            break;
        case 6:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; }
            else { cout << "Nhung san pham co don gia > 250.000 dong: " << endl; myList.showUpper250K(); }
            break;
        case 7:
            if (!isInit) { cout << "Ban chua khoi tao danh sach! Hay khoi tao danh sach!"; continue; } 
            else { cout << "Thong tin cua don gia cao nhat: " << endl; myList.showHiggest(); }
     
            break;
        default:
            break;
        }
        system("pause");
    }
      
    return 0;
}
