#include <stdio.h>
#include <string.h>

#define MAX_NHAN_VIEN 100

typedef struct {
    int maNV;
    char hoTen[50];
    float luongCoBan;
    int phutMuon;
    float soGioOT;
} NhanVien;

// Khai bao nguyen mau ham
void hienThiMenu(void);
int timKiemTheoMa(NhanVien ds[], int soLuong, int maNV);
void hienThiDanhSach(NhanVien ds[], int soLuong);
int themNhanVien(NhanVien ds[], int soLuong);
void suaNhanVien(NhanVien ds[], int soLuong);
int xoaNhanVien(NhanVien ds[], int soLuong);
int nhapSoNguyen(char thongBao[]);
float nhapSoThuc(char thongBao[]);
void nhapHoTen(char hoTen[], int kichThuoc);

int main(void) {
    NhanVien ds[MAX_NHAN_VIEN];
    int soLuong = 0;
    int luaChon;

    do {
        hienThiMenu();
        luaChon = nhapSoNguyen("Nhap lua chon: ");

        switch (luaChon) {
            case 1:
                hienThiDanhSach(ds, soLuong);
                break;
            case 2:
                soLuong = themNhanVien(ds, soLuong);
                break;
            case 3:
                suaNhanVien(ds, soLuong);
                break;
            case 4:
                soLuong = xoaNhanVien(ds, soLuong);
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}

// Hien thi menu
void hienThiMenu(void) {
    printf("\n===== HE THONG QUAN LY NHAN SU HRM =====\n");
    printf("1. Xem danh sach nhan vien va bang luong\n");
    printf("2. Them nhan vien moi\n");
    printf("3. Cap nhat thong tin nhan vien\n");
    printf("4. Xoa nhan vien\n");
    printf("0. Thoat chuong trinh\n");
    printf("=======================================\n");
}

// Nhap so nguyen, khong chap nhan ky tu thua
int nhapSoNguyen(char thongBao[]) {
    char dong[100];
    int giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %d %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le! Hay nhap so nguyen.\n");
    }
}

// Nhap so thuc
float nhapSoThuc(char thongBao[]) {
    char dong[100];
    float giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %f %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le! Hay nhap so.\n");
    }
}

// Nhap ho ten co khoang trang
void nhapHoTen(char hoTen[], int kichThuoc) {
    while (1) {
        printf("Ho ten: ");

        if (fgets(hoTen, kichThuoc, stdin) == NULL) {
            hoTen[0] = '\0';
            return;
        }

        if (strchr(hoTen, '\n') == NULL) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        hoTen[strcspn(hoTen, "\n")] = '\0';

        if (hoTen[0] != '\0') {
            return;
        }

        printf("Ho ten khong duoc de trong!\n");
    }
}

// Tim nhan vien theo ma, tra ve vi tri hoac -1
int timKiemTheoMa(NhanVien ds[], int soLuong, int maNV) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (ds[i].maNV == maNV) {
            return i;
        }
    }

    return -1;
}

// Hien thi danh sach va bang luong
void hienThiDanhSach(NhanVien ds[], int soLuong) {
    int i;
    int tienPhat;
    float tienOT;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    printf("\n--- DANH SACH NHAN VIEN ---\n");

    for (i = 0; i < soLuong; i++) {
        tienPhat = ds[i].phutMuon > 15 ? 50000 : 0;
        tienOT = ds[i].soGioOT * (ds[i].luongCoBan / 160.0f) * 1.5f;
        luongThucNhan = ds[i].luongCoBan + tienOT - tienPhat;

        printf("\nMa NV: %d\n", ds[i].maNV);
        printf("Ho ten: %s\n", ds[i].hoTen);
        printf("Luong co ban: %.0f VND\n", ds[i].luongCoBan);
        printf("Phut muon: %d\n", ds[i].phutMuon);
        printf("Gio OT: %.2f\n", ds[i].soGioOT);
        printf("Tien phat: %d VND\n", tienPhat);
        printf("Tien OT: %.0f VND\n", tienOT);
        printf("Luong thuc nhan: %.0f VND\n", luongThucNhan);
    }

    printf("\nTong so nhan vien: %d\n", soLuong);
}

// Them nhan vien
int themNhanVien(NhanVien ds[], int soLuong) {
    NhanVien nv;

    printf("\n--- THEM NHAN VIEN ---\n");

    if (soLuong >= MAX_NHAN_VIEN) {
        printf("Danh sach da day!\n");
        return soLuong;
    }

    nv.maNV = nhapSoNguyen("Ma NV: ");

    if (nv.maNV <= 0) {
        printf("Ma nhan vien phai la so nguyen duong!\n");
        return soLuong;
    }

    if (timKiemTheoMa(ds, soLuong, nv.maNV) != -1) {
        printf("Loi: Ma nhan vien da ton tai!\n");
        return soLuong;
    }

    nhapHoTen(nv.hoTen, sizeof(nv.hoTen));

    nv.luongCoBan = nhapSoThuc("Luong co ban: ");
    if (nv.luongCoBan < 0) {
        printf("Luong co ban khong duoc am!\n");
        return soLuong;
    }

    nv.phutMuon = nhapSoNguyen("Phut di muon: ");
    if (nv.phutMuon < 0) {
        printf("So phut di muon khong duoc am!\n");
        return soLuong;
    }

    nv.soGioOT = nhapSoThuc("So gio OT: ");
    if (nv.soGioOT < 0) {
        printf("So gio OT khong duoc am!\n");
        return soLuong;
    }

    ds[soLuong] = nv;
    soLuong++;

    printf("Them nhan vien thanh cong!\n");
    return soLuong;
}

// Sua luong co ban, phut muon va gio OT
void suaNhanVien(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    float luongMoi;
    int phutMuonMoi;
    float gioOTMoi;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    maNV = nhapSoNguyen("Nhap ma NV can cap nhat: ");
    viTri = timKiemTheoMa(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    luongMoi = nhapSoThuc("Nhap luong co ban moi: ");
    if (luongMoi < 0) {
        printf("Luong co ban khong duoc am!\n");
        return;
    }

    phutMuonMoi = nhapSoNguyen("Nhap so phut di muon moi: ");
    if (phutMuonMoi < 0) {
        printf("So phut di muon khong duoc am!\n");
        return;
    }

    gioOTMoi = nhapSoThuc("Nhap so gio OT moi: ");
    if (gioOTMoi < 0) {
        printf("So gio OT khong duoc am!\n");
        return;
    }

    ds[viTri].luongCoBan = luongMoi;
    ds[viTri].phutMuon = phutMuonMoi;
    ds[viTri].soGioOT = gioOTMoi;

    printf("Cap nhat nhan vien thanh cong!\n");
}

// Xoa nhan vien va dich cac phan tu phia sau len
int xoaNhanVien(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    int i;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return soLuong;
    }

    maNV = nhapSoNguyen("Ma NV can xoa: ");
    viTri = timKiemTheoMa(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return soLuong;
    }

    for (i = viTri; i < soLuong - 1; i++) {
        ds[i] = ds[i + 1];
    }

    soLuong--;
    printf("Xoa nhan vien thanh cong!\n");

    return soLuong;
}