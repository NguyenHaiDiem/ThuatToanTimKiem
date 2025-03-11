#include <iostream>
#include <string>
#define nullptr NULL
using namespace std;

struct SinhVien {
    string ma_sv;
    string ho_ten;
    int nam_sinh;
    float diem_tb;
};
void inThongTin(const SinhVien& sv) {
    cout << "Ma SV: " << sv.ma_sv << ", Ho ten: " << sv.ho_ten << ", Nam sinh: " << sv.nam_sinh << ", Diem TB: " << sv.diem_tb << endl;
}
void nhapDanhSachSinhVien(SinhVien danh_sach[], int& n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "Ma SV: "; cin >> danh_sach[i].ma_sv;
        cout << "Ho ten: "; cin.ignore(); getline(cin, danh_sach[i].ho_ten);
        cout << "Nam sinh: "; cin >> danh_sach[i].nam_sinh;
        cout << "Diem TB: "; cin >> danh_sach[i].diem_tb;
    }
}
SinhVien* timKiemTuyenTinh(SinhVien danh_sach[], int n, const string& ma_sv) {
    for (int i = 0; i < n; i++) {
        if (danh_sach[i].ma_sv == ma_sv) {
            return &danh_sach[i];
        }
    }
    return nullptr;
}
SinhVien* timKiemNhiPhan(SinhVien danh_sach[], int n, const string& ma_sv) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (danh_sach[mid].ma_sv == ma_sv) {
            return &danh_sach[mid];
        }
        if (danh_sach[mid].ma_sv < ma_sv) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;
}
void sapXepNoiBot(SinhVien danh_sach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (danh_sach[j].ma_sv > danh_sach[j + 1].ma_sv) {
                swap(danh_sach[j], danh_sach[j + 1]);
            }
        }
    }
}
int main() {
    const int MAX_SV = 100; 
    SinhVien danh_sach[MAX_SV];
    int n;
    nhapDanhSachSinhVien(danh_sach, n);
    sapXepNoiBot(danh_sach, n);
    string ma_sv_can_tim;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> ma_sv_can_tim;

    SinhVien* sv = timKiemTuyenTinh(danh_sach, n, ma_sv_can_tim);
    if (sv) {
        cout << "Tim kiem tuyen tinh: ";
        inThongTin(*sv);
    } else {
        cout << "Khong tim thay sinh vien co ma " << ma_sv_can_tim << endl;
    }
    
    sv = timKiemNhiPhan(danh_sach, n, ma_sv_can_tim);
    if (sv) {
        cout << "Tim kiem nhi phan: ";
        inThongTin(*sv);
    } else {
        cout << "Khong tim thay sinh vien co ma " << ma_sv_can_tim << endl;
    }

    cout << "Danh sach sinh vien sau khi sap xep:\n";
    for (int i = 0; i < n; i++) {
        inThongTin(danh_sach[i]);
    }

    return 0;
}
