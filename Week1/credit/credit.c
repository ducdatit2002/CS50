#include <cs50.h>
#include <stdio.h>

int main(void)
{
       long long creditCardNumbers;

    // Nhập số thẻ tín dụng từ người dùng
    do {
        creditCardNumbers = get_long("Vui long nhap so the tin dung: ");
    } while (creditCardNumbers <= 0);

    // Tính tổng các chữ số đã nhân 2
    int sum_Double = 0;
    long long tempNum = creditCardNumbers;
    int count = 0;

    while (tempNum > 0) {
        int digit = tempNum % 10;
        if (count % 2 == 1) {
            int doubled = digit * 2;
            while (doubled > 0) {
                sum_Double += doubled % 10;
                doubled /= 10;
            }
        } else {
            sum_Double += digit;
        }
        tempNum /= 10;
        count++;
    }

    // Kiểm tra hợp lệ loại thẻ
    if (sum_Double % 10 == 0) {
        if ((creditCardNumbers >= 340000000000000 && creditCardNumbers < 350000000000000) ||
            (creditCardNumbers >= 370000000000000 && creditCardNumbers < 380000000000000)) {
            printf("AMEX\n");
        } else if (creditCardNumbers >= 5100000000000000 && creditCardNumbers < 5600000000000000) {
            printf("MASTERCARD\n");
        } else if ((creditCardNumbers >= 4000000000000 && creditCardNumbers < 5000000000000) ||
                   (creditCardNumbers >= 4000000000000000 && creditCardNumbers < 5000000000000000)) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}