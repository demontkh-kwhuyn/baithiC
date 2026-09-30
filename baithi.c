#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
    int n = 5;
    int choice;

    do {
        printf("\n=====================================================\n");
        printf("         CHUONG TRINH QUAN LY TON KHO MINIMART\n");
        printf("=====================================================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("5. Hien thi danh sach ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                } else {
                    int value, pos;
                    printf("Nhap gia tri can them (value): ");
                    scanf("%d", &value);
                    printf("Nhap vi tri chen (pos tu 1 den %d): ", n + 1);
                    scanf("%d", &pos);

                    if (pos < 1 || pos > n + 1) {
                        printf("Vi tri chen khong hop le!\n");
                    } else {
                        for (int i = n; i >= pos; i--) {
                            stock[i] = stock[i - 1];
                        }
                        stock[pos - 1] = value;
                        n++;
                        
                        printf("Ket qua: [");
                        for (int i = 0; i < n; i++) {
                            printf("%d", stock[i]);
                            if (i < n - 1) printf(", ");
                        }
                        printf("]\n");
                    }
                }
                break;
            }
            case 2: {
                int pos, newValue;
                printf("Nhap vi tri can sua (pos tu 1 den %d): ", n);
                scanf("%d", &pos);
                printf("Nhap gia tri moi (newValue): ");
                scanf("%d", &newValue);

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                } else if (newValue < 0) {
                    printf("So luong ton kho khong hop le!\n");
                } else {
                    stock[pos - 1] = newValue;
                    
                    printf("Ket qua: [");
                    for (int i = 0; i < n; i++) {
                        printf("%d", stock[i]);
                        if (i < n - 1) printf(", ");
                    }
                    printf("]\n");
                }
                break;
            }
            case 3: {
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                } else {
                    int pos;
                    printf("Nhap vi tri can xoa (pos tu 1 den %d): ", n);
                    scanf("%d", &pos);

                    if (pos < 1 || pos > n) {
                        printf("Vi tri xoa khong hop le!\n");
                    } else {
                        for (int i = pos - 1; i < n - 1; i++) {
                            stock[i] = stock[i + 1];
                        }
                        n--;
                        
                        printf("Ket qua: [");
                        for (int i = 0; i < n; i++) {
                            printf("%d", stock[i]);
                            if (i < n - 1) printf(", ");
                        }
                        printf("]\n");
                    }
                }
                break;
            }
            case 4: {
                int target;
                printf("Nhap gia tri can tim (target): ");
                scanf("%d", &target);
                int foundCount = 0;

                printf("Cac vi tri tim thay: ");
                for (int i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        printf("%d ", i + 1);
                        foundCount++;
                    }
                }
                if (foundCount > 0) {
                    printf("\nTong so lan xuat hien: %d\n", foundCount);
                } else {
                    printf("\nKhong tim thay gia tri trong mang!\n");
                }
                break;
            }
            case 5: {
                if (n == 0) {
                    printf("Danh sach ton kho hien tai dang trong!\n");
                } else {
                    printf("Danh sach so luong ton kho hien tai:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Vi tri %d: %d\n", i + 1, stock[i]);
                    }
                    printf("Dang mang: [");
                    for (int i = 0; i < n; i++) {
                        printf("%d", stock[i]);
                        if (i < n - 1) printf(", ");
                    }
                    printf("]\n");
                }
                break;
            }
            case 0:
                printf("Thoat chuong trinh. Tam biet ban!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap tu 0 den 5.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
