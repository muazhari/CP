#include <stdio.h>

int main()
{
    //semua statement kodingan awal distart disini

    // contoh iterasi, 0 - 9

    int count_i = 0;
    for (int i = 0; i < 10; i += 1)
    {
        count_i += 1;
    }

    printf("banyak iterasi = %d\n", count_i);

    //latihan:
    //1 < x < 200, berapa (x - 2) % 2 == 0

    // contoh O(n)
    int count_n = 0;

    for (int x = 1; x <= 310; x += 1)
    {
        if ((x - 2) % 2 == 0) 
        // jika kondisi memenhi jalankan statement
        // didalam bracket
        {
            count_n += 1; // increment variabel count_n dengan +1
        }
    }

    //contoh O(1)
    //waduh IQ gw wkwk
    // barbar ya penjelasannya
    // dari setiap x dikurang 2 yg dikurang pasti tetap genap bukan?
    // karena tetap dikurang bilangan genap juga
    // nah karena gw gatau kenapa mines % 2 bisa 0, jadi asumsi diitung
    // jadi sama aja ngitung berapa jumlah genap dari semua angka 1 - 200
    // jadi nya x % 2==0 disetiap x jadi sama aja total / 2
    // sori IQ gw mampet

    int count_1 = 310 / 2;
    //coba kita check selain 200, sama atau engga
    printf("banyak x yang (x - 2) mod 2 == 0 ialah %d", count_n);
    printf("banyak x yang (x - 2) mod 2 == 0 ialah %d", count_1);

    // dan samaa wkkwk

    

    //penjelasan for-loop
    for(deklarasi intial var; selama kondisi benar; jalankan statement2){
        // statement1 block for terjalankan sehabis diatas
        // kemudian kembali urutan kondisi-> stament1-> staement2
    }

    mirip kyk gini

    deklarasi var;
    while(kondisi benar, kondisi bisa dicek ke var apa aja){
        staement1
        statement2
    }

    //contoh loop lagi

    //pembelahan bakteri
    // ini jadi tampungan berapa bakteri total
    int n_bakteri = 0;
    ini r mula-mula, kalo diganti x ya dari mana bisa nambah r*r
             |          dari statement ini
             |               |
             V               V
    for (int r=2 ; r<2000; r=*r){
                    ^
                    |
            kalo yg ini dilimit yg

        ini statement  total bakteri sekarang
        n_bakteri = r
    }

    // ini simpelnya 
    tapi umumnya gini
    int count_i = 0;
    for (int i = 0; i < 10; i += 1)
    {
        count_i += 1;
    }

    // bisa gini
    
    for (int i = 0; i < 10; count_i+=1)
    {
        i+=1;
    }

    return 0;

    ini for loop
    for(initial;kondisi;statement){staement block}
}

