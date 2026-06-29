#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

template<typename T>
string to_string(T value)
{
    stringstream ss;
    ss << value;
    return ss.str();
}

/* =========================
   CLASS FILM
========================= */
class Film {
public:
    string idFilm;
    string judulFilm;
    string genre;
    int durasi;
    double hargaTiket;
};

/* =========================
   CLASS TIKET
========================= */
class Tiket {
public:
    string judulFilm;
    int durasi;
    string rating;
    string lokasi;

    int tanggal;
    int bulan;
    int tahun;

    int waktuMulai;
    int waktuSelesai;

    string studio;
    int jumlahTiket;
    string kursi[10];
    double harga;

    void output() {

        cout << "\n====================================\n";
        cout << "           TICKET DETAIL\n";
        cout << "====================================\n";

        cout << "Film          : " << judulFilm << endl;
        cout << "Durasi        : " << durasi << " Minutes" << endl;
        cout << "Rating        : " << rating << endl;
        cout << "Lokasi        : " << lokasi << endl;

        cout << "Tanggal       : "
             << tanggal << "/"
             << bulan << "/"
             << tahun << endl;

        cout << "Jam           : "
             << waktuMulai << ".00 - "
             << waktuSelesai << ".00" << endl;

        cout << "Studio        : " << studio << endl;

        cout << "Kursi         : ";

        for(int i=0;i<jumlahTiket;i++)
        {
            cout << kursi[i];

            if(i<jumlahTiket-1)
                cout << ", ";
        }

        cout<<endl;
        cout << "Jumlah Tiket  : " << jumlahTiket << endl;
        cout<<"---------------------------------------------"<<endl;
        cout << "Harga/Tiket   : Rp " << harga << endl;
        cout << "Total Bayar   : Rp " << harga*jumlahTiket << endl;

        cout << "====================================\n";
    }
};

/* =========================
   DATA FILM (20 FILM FIX)
========================= */
Film film[20] = {
    {"F01","Avengers Endgame","Action",181,50000},
    {"F02","Spider-Man NWH","Action",148,45000},
    {"F03","The Batman","Action",176,48000},
    {"F04","Joker","Drama",122,40000},
    {"F05","Interstellar","Sci-Fi",169,55000},
    {"F06","Inception","Sci-Fi",148,52000},
    {"F07","Titanic","Romance",195,45000},
    {"F08","The Nun","Horror",96,40000},
    {"F09","Annabelle","Horror",99,38000},
    {"F10","Conjuring","Horror",112,42000},
    {"F11","Fast Furious 10","Action",141,50000},
    {"F12","Minions","Animation",91,35000},
    {"F13","Frozen II","Animation",103,38000},
    {"F14","Moana","Animation",107,37000},
    {"F15","Dune","Sci-Fi",155,53000},
    {"F16","Doctor Strange","Action",126,47000},
    {"F17","Black Panther","Action",134,48000},
    {"F18","Coco","Animation",105,36000},
    {"F19","Parasite","Drama",132,42000},
    {"F20","John Wick 4","Action",169,50000}
};

/* =========================
   CLASS GENRE
========================= */
class Genre {
public:
    string namaGenre;
    string keterangan;

    void tampilGenre() {
        cout << "Genre      : " << namaGenre << endl;
        cout << "Keterangan : " << keterangan << endl;
    }
};

/* =========================
   CLASS STUDIO
========================= */
class Studio {
public:
    string kodeStudio;
    string namaStudio;
    int kapasitas;

    void tampilStudio() {
        cout << "Studio     : " << namaStudio << endl;
        cout << "Kapasitas  : " << kapasitas << " Kursi" << endl;
    }
};

/* =========================
   CLASS JADWAL
========================= */
class Jadwal {
public:
    string tanggal;
    string jamMulai;
    string jamSelesai;

    void tampilJadwal() {
        cout << "Tanggal    : " << tanggal << endl;
        cout << "Jam        : " << jamMulai
             << " - "
             << jamSelesai << endl;
    }
};

/* =========================
   CLASS KURSI
========================= */
class Kursi {
public:
    string kodeKursi;
    bool status;

    void tampilStatus() {
        cout << kodeKursi << " : ";

        if(status)
            cout << "Terisi";
        else
            cout << "Kosong";

        cout << endl;
    }
};

Kursi daftarKursi[100];

void inisialisasiKursi()
{
    int index = 0;

    for(char baris='A'; baris<='J'; baris++)
    {
        for(int nomor=1; nomor<=10; nomor++)
        {
            daftarKursi[index].kodeKursi = "";

            daftarKursi[index].kodeKursi += baris;

            if(nomor<10)
                daftarKursi[index].kodeKursi += "0";

            if(nomor==10)
                daftarKursi[index].kodeKursi+="10";
            else
                daftarKursi[index].kodeKursi+=char('0'+nomor);

            daftarKursi[index].status = false;

            index++;
        }
    }
}

void tampilKursi()
{
    cout<<"\n============================================\n";
    cout<<"               LAYAR BIOSKOP\n";
    cout<<"============================================\n\n";

    int index=0;

    for(char baris='A'; baris<='J'; baris++)
    {
        for(int nomor=1; nomor<=10; nomor++)
        {
            if(daftarKursi[index].status)
                cout<<"[XX] ";
            else
                cout<<"["<<daftarKursi[index].kodeKursi<<"] ";

            index++;
        }

        cout<<endl<<endl;
    }

    cout<<"\nXX = Terisi\n";
}

void pilihKursi(Tiket &t)
{
    tampilKursi();

    cout<<"\nJumlah Tiket : ";
    cin>>t.jumlahTiket;

    for(int i=0;i<t.jumlahTiket;i++)
    {
        string pilih;

        cout<<"Pilih Kursi "<<i+1<<" : ";
        cin>>pilih;

        bool ditemukan=false;

        for(int j=0;j<100;j++)
        {
            if(daftarKursi[j].kodeKursi==pilih)
            {
                if(daftarKursi[j].status)
                {
                    cout<<"Kursi sudah terisi!\n";
                    i--;
                }
                else
                {
                    daftarKursi[j].status=true;
                    t.kursi[i]=pilih;
                }

                ditemukan=true;
                break;
            }
        }

        if(!ditemukan)
        {
            cout<<"Kode kursi tidak ada!\n";
            i--;
        }

        tampilKursi();
    }
}

/* =========================
   CLASS PEMBAYARAN
========================= */
class Pembayaran {
public:
    string metode;
    double totalBayar;

    void tampilPembayaran() {
        cout << "\n========== PEMBAYARAN ==========\n";
        cout << "Metode     : " << metode << endl;
        cout << "Total      : Rp " << totalBayar << endl;
        cout << "===============================\n";
    }
};

/* =========================
   CLASS TRANSAKSI
========================= */
class Transaksi {
public:
    string kodeTransaksi;
    string namaPelanggan;
    Film dataFilm;
    Pembayaran bayar;

    void tampilTransaksi() {

        cout << "\n========== TRANSAKSI ==========\n";

        cout << "Kode       : "
             << kodeTransaksi << endl;

        cout << "Nama       : "
             << namaPelanggan << endl;

        cout << "Film       : "
             << dataFilm.judulFilm << endl;

        cout << "Harga      : Rp "
             << dataFilm.hargaTiket << endl;

        cout << "Metode     : "
             << bayar.metode << endl;

        cout << "Total      : Rp "
             << bayar.totalBayar << endl;

        cout << "===============================\n";

    }

};

/* =========================
   CLASS LAPORAN
========================= */
class Laporan {
public:

    int totalTiket;
    double totalPendapatan;

    void tampilLaporan() {

        cout << "\n====================================\n";
        cout << "       LAPORAN PENJUALAN TIKET\n";
        cout << "====================================\n";

        cout << "Total Tiket Terjual : "
             << totalTiket << endl;

        cout << "Total Pendapatan    : Rp "
             << totalPendapatan << endl;

        cout << "====================================\n";

    }

};

/* =========================
   TAMPILKAN DAFTAR FILM
========================= */
void tampilDaftarFilm() {

    cout << "\n==========================================================================\n";
    cout << "                         DAFTAR FILM CGV\n";
    cout << "==========================================================================\n";

    cout << "ID    "
         << "Judul Film"
         << "\t\tGenre\t\tHarga\n";

    cout << "--------------------------------------------------------------------------\n";

    for(int i=0;i<20;i++) {

        cout << film[i].idFilm << "   ";

        cout << film[i].judulFilm;

        if(film[i].judulFilm.length()<16)
            cout << "\t\t";
        else
            cout << "\t";

        cout << film[i].genre << "\t";

        cout << "Rp "
             << film[i].hargaTiket
             << endl;

    }

    cout << "==========================================================================\n";

}

/* =========================
   CARI FILM BERDASARKAN ID
========================= */
Film cariFilm(string id) {

    for(int i=0;i<20;i++) {

        if(film[i].idFilm==id)
            return film[i];

    }

    return film[0];
}

/* =========================
   PILIH FILM
========================= */
Film pilihFilm() {

    int pilihan;

    do {

        cout << "\n=====================================\n";
        cout << "          PILIH FILM CGV\n";
        cout << "=====================================\n";

        for(int i=0; i<20; i++) {
            cout << i+1 << ". "
                 << film[i].judulFilm
                 << " (Rp " << film[i].hargaTiket << ")"
                 << endl;
        }

        cout << "=====================================\n";
        cout << "Masukkan pilihan (1-20) : ";
        cin >> pilihan;

        if(pilihan < 1 || pilihan > 20)
            cout << "Pilihan tidak valid!\n";

    }while(pilihan < 1 || pilihan > 20);

    return film[pilihan-1];

}

/* =====================================================
   =================== FITUR BARU ====================
   ===================================================*/

/* =========================
   CLASS MEMBER / PELANGGAN
========================= */
class Member {
public:
    string idMember;
    string nama;
    string noHp;
    string email;
    int poin;
    string levelMember; // Regular, Silver, Gold, Platinum

    Member() {
        idMember = "";
        nama = "";
        noHp = "";
        email = "";
        poin = 0;
        levelMember = "Regular";
    }

    // Hitung level berdasarkan poin
    void updateLevel() {
        if(poin >= 5000) {
            levelMember = "Platinum";
        } else if(poin >= 2000) {
            levelMember = "Gold";
        } else if(poin >= 500) {
            levelMember = "Silver";
        } else {
            levelMember = "Regular";
        }
    }

    // Tambah poin dari pembelian
    void tambahPoin(double totalBayar) {
        // Setiap Rp 10.000 dapat 1 poin
        int poinBaru = (int)(totalBayar / 10000);
        poin += poinBaru;
        updateLevel();
        cout << "\n[+] Poin bertambah: +" << poinBaru << " poin" << endl;
        cout << "[*] Total Poin     : " << poin << " poin" << endl;
    }

    // Tampilkan info member
    void tampilMember() {
        cout << "\n====================================\n";
        cout << "          INFO MEMBER CGV\n";
        cout << "====================================\n";
        cout << "ID Member  : " << idMember << endl;
        cout << "Nama       : " << nama << endl;
        cout << "No. HP     : " << noHp << endl;
        cout << "Email      : " << email << endl;
        cout << "Poin       : " << poin << endl;
        cout << "Level      : " << levelMember << endl;
        cout << "====================================\n";
    }

    // Dapatkan diskon berdasarkan level
    double getDiskon() {
        if(levelMember == "Platinum") return 0.20;
        else if(levelMember == "Gold") return 0.15;
        else if(levelMember == "Silver") return 0.10;
        else return 0.0;
    }

    // Tampilkan diskon member
    void tampilDiskon() {
        double diskon = getDiskon();
        cout << "\n[INFO] Level Member : " << levelMember << endl;
        if(diskon > 0) {
            cout << "[INFO] Diskon Member: " << (int)(diskon*100) << "%" << endl;
        } else {
            cout << "[INFO] Tidak ada diskon untuk member Regular." << endl;
        }
    }
};

/* =========================
   DATA MEMBER GLOBAL
========================= */
Member daftarMember[50];
int jumlahMember = 0;

// Daftarkan member baru
Member daftarMemberBaru() {
    Member m;
    cout << "\n====================================\n";
    cout << "        PENDAFTARAN MEMBER CGV\n";
    cout << "====================================\n";

    // Generate ID otomatis
    string prefix = "MBR";
    int urutan = jumlahMember + 1;
    string idStr = "";
    if(urutan < 10) idStr = "00" + char('0' + urutan);
    else idStr = to_string(urutan);
    m.idMember = prefix + idStr;

    cin.ignore();
    cout << "Nama Lengkap   : ";
    getline(cin, m.nama);

    cout << "No. HP         : ";
    getline(cin, m.noHp);

    cout << "Email          : ";
    getline(cin, m.email);

    m.poin = 0;
    m.levelMember = "Regular";

    daftarMember[jumlahMember] = m;
    jumlahMember++;

    cout << "\n[SUKSES] Member berhasil didaftarkan!\n";
    m.tampilMember();

    return m;
}

// Cari member berdasarkan nama
Member* cariMemberByNama(string nama) {
    for(int i = 0; i < jumlahMember; i++) {
        if(daftarMember[i].nama == nama) {
            return &daftarMember[i];
        }
    }
    return NULL;
}

// Cari member berdasarkan ID
Member* cariMemberById(string id) {
    for(int i = 0; i < jumlahMember; i++) {
        if(daftarMember[i].idMember == id) {
            return &daftarMember[i];
        }
    }
    return NULL;
}

// Tampilkan semua member
void tampilSemuaMember() {
    cout << "\n====================================\n";
    cout << "       DAFTAR MEMBER CGV\n";
    cout << "====================================\n";
    if(jumlahMember == 0) {
        cout << "Belum ada member terdaftar.\n";
    } else {
        for(int i = 0; i < jumlahMember; i++) {
            cout << i+1 << ". "
                 << daftarMember[i].idMember << " | "
                 << daftarMember[i].nama << " | "
                 << "Poin: " << daftarMember[i].poin << " | "
                 << "Level: " << daftarMember[i].levelMember
                 << endl;
        }
    }
    cout << "====================================\n";
}

/* =========================
   CLASS SNACK / MAKANAN
========================= */
class Snack {
public:
    string kodeSnack;
    string namaSnack;
    string kategori;
    double harga;
    bool tersedia;

    void tampilSnack() {
        cout << kodeSnack << " | "
             << namaSnack;
        // padding
        int pad = 20 - namaSnack.length();
        for(int i = 0; i < pad; i++) cout << " ";
        cout << "| " << kategori;
        int pad2 = 12 - kategori.length();
        for(int i = 0; i < pad2; i++) cout << " ";
        cout << "| Rp " << harga;
        if(!tersedia) cout << " [HABIS]";
        cout << endl;
    }
};

/* =========================
   DATA SNACK
========================= */
Snack daftarSnack[15] = {
    {"SK01","Popcorn Caramel","Snack",30000,true},
    {"SK02","Popcorn Asin","Snack",25000,true},
    {"SK03","Popcorn Keju","Snack",28000,true},
    {"SK04","Nachos","Snack",35000,true},
    {"SK05","Hot Dog","Makanan",40000,true},
    {"SK06","French Fries","Makanan",32000,true},
    {"SK07","Cola Large","Minuman",20000,true},
    {"SK08","Cola Medium","Minuman",15000,true},
    {"SK09","Mineral Water","Minuman",10000,true},
    {"SK10","Orange Juice","Minuman",22000,true},
    {"SK11","Combo A (Popcorn+Cola)","Paket",45000,true},
    {"SK12","Combo B (Nachos+Cola)","Paket",50000,true},
    {"SK13","Combo C (HotDog+Fries+Cola)","Paket",65000,true},
    {"SK14","Choco Lava","Dessert",38000,true},
    {"SK15","Ice Cream Cup","Dessert",25000,false}
};

// Tampilkan menu snack
void tampilMenuSnack() {
    cout << "\n=============================================================\n";
    cout << "                    MENU SNACK CGV\n";
    cout << "=============================================================\n";
    cout << "Kode | Nama                 | Kategori    | Harga\n";
    cout << "-------------------------------------------------------------\n";
    for(int i = 0; i < 15; i++) {
        daftarSnack[i].tampilSnack();
    }
    cout << "=============================================================\n";
}

// Struct untuk menyimpan pesanan snack
struct PesananSnack {
    string kodeSnack;
    string namaSnack;
    int jumlah;
    double harga;
    double subtotal;
};

// Proses pemesanan snack
void pesanSnack(PesananSnack pesanan[], int &jumlahPesanan, double &totalSnack) {
    char lagi;
    jumlahPesanan = 0;
    totalSnack = 0;

    do {
        tampilMenuSnack();
        string pilih;
        cout << "\nMasukkan Kode Snack (atau '0' untuk selesai): ";
        cin >> pilih;

        if(pilih == "0") break;

        bool ditemukan = false;
        for(int i = 0; i < 15; i++) {
            if(daftarSnack[i].kodeSnack == pilih) {
                ditemukan = true;
                if(!daftarSnack[i].tersedia) {
                    cout << "[!] Snack sedang habis!\n";
                    break;
                }
                int jumlah;
                cout << "Jumlah " << daftarSnack[i].namaSnack << ": ";
                cin >> jumlah;
                if(jumlah < 1) {
                    cout << "[!] Jumlah tidak valid!\n";
                    break;
                }
                pesanan[jumlahPesanan].kodeSnack  = daftarSnack[i].kodeSnack;
                pesanan[jumlahPesanan].namaSnack  = daftarSnack[i].namaSnack;
                pesanan[jumlahPesanan].jumlah     = jumlah;
                pesanan[jumlahPesanan].harga      = daftarSnack[i].harga;
                pesanan[jumlahPesanan].subtotal   = daftarSnack[i].harga * jumlah;
                totalSnack += pesanan[jumlahPesanan].subtotal;
                jumlahPesanan++;
                cout << "[+] Ditambahkan ke pesanan.\n";
                break;
            }
        }

        if(!ditemukan) {
            cout << "[!] Kode snack tidak ditemukan!\n";
        }

        if(jumlahPesanan >= 10) {
            cout << "[!] Maksimal 10 item snack.\n";
            break;
        }

        cout << "\nTambah snack lagi? (y/n): ";
        cin >> lagi;

    } while(lagi == 'y' || lagi == 'Y');
}

// Tampilkan ringkasan snack yang dipesan
void tampilPesananSnack(PesananSnack pesanan[], int jumlahPesanan, double totalSnack) {
    if(jumlahPesanan == 0) {
        cout << "\n[INFO] Tidak ada pesanan snack.\n";
        return;
    }
    cout << "\n====================================\n";
    cout << "       PESANAN SNACK\n";
    cout << "====================================\n";
    for(int i = 0; i < jumlahPesanan; i++) {
        cout << pesanan[i].namaSnack
             << " x" << pesanan[i].jumlah
             << "  = Rp " << pesanan[i].subtotal << endl;
    }
    cout << "------------------------------------\n";
    cout << "Total Snack : Rp " << totalSnack << endl;
    cout << "====================================\n";
}

/* =========================
   CLASS ULASAN FILM
========================= */
class Ulasan {
public:
    string idFilm;
    string judulFilm;
    string namaPenonton;
    int bintang;       // 1-5
    string komentar;

    Ulasan() {
        idFilm = "";
        judulFilm = "";
        namaPenonton = "";
        bintang = 0;
        komentar = "";
    }

    void tampilUlasan() {
        cout << "-----------------------------------\n";
        cout << "Film     : " << judulFilm << endl;
        cout << "Penonton : " << namaPenonton << endl;
        cout << "Bintang  : ";
        for(int i = 0; i < bintang; i++) cout << "*";
        for(int i = bintang; i < 5; i++) cout << ".";
        cout << " (" << bintang << "/5)" << endl;
        cout << "Komentar : " << komentar << endl;
    }
};

/* =========================
   DATA ULASAN GLOBAL
========================= */
Ulasan daftarUlasan[100];
int jumlahUlasan = 0;

// Input ulasan baru
void inputUlasan(string idFilm, string judulFilm, string namaPenonton) {
    if(jumlahUlasan >= 100) {
        cout << "[!] Kapasitas ulasan penuh.\n";
        return;
    }

    Ulasan u;
    u.idFilm = idFilm;
    u.judulFilm = judulFilm;
    u.namaPenonton = namaPenonton;

    cout << "\n====================================\n";
    cout << "       BERIKAN ULASAN FILM\n";
    cout << "====================================\n";
    cout << "Film : " << judulFilm << endl;

    int bintang;
    do {
        cout << "Bintang (1-5): ";
        cin >> bintang;
        if(bintang < 1 || bintang > 5)
            cout << "[!] Masukkan angka 1-5!\n";
    } while(bintang < 1 || bintang > 5);
    u.bintang = bintang;

    cin.ignore();
    cout << "Komentar     : ";
    getline(cin, u.komentar);

    daftarUlasan[jumlahUlasan] = u;
    jumlahUlasan++;

    cout << "\n[SUKSES] Ulasan berhasil disimpan!\n";
}

// Tampilkan ulasan berdasarkan film
void tampilUlasanFilm(string idFilm) {
    cout << "\n====================================\n";
    cout << "       ULASAN FILM\n";
    cout << "====================================\n";

    bool ada = false;
    int totalBintang = 0;
    int count = 0;

    for(int i = 0; i < jumlahUlasan; i++) {
        if(daftarUlasan[i].idFilm == idFilm) {
            daftarUlasan[i].tampilUlasan();
            totalBintang += daftarUlasan[i].bintang;
            count++;
            ada = true;
        }
    }

    if(!ada) {
        cout << "Belum ada ulasan untuk film ini.\n";
    } else {
        double rata = (double)totalBintang / count;
        cout << "-----------------------------------\n";
        cout << "Rata-rata Bintang : " << fixed << setprecision(1) << rata << "/5 dari " << count << " ulasan\n";
    }

    cout << "====================================\n";
}

// Tampilkan semua ulasan
void tampilSemuaUlasan() {
    cout << "\n====================================\n";
    cout << "         SEMUA ULASAN FILM\n";
    cout << "====================================\n";
    if(jumlahUlasan == 0) {
        cout << "Belum ada ulasan.\n";
    } else {
        for(int i = 0; i < jumlahUlasan; i++) {
            daftarUlasan[i].tampilUlasan();
        }
    }
    cout << "====================================\n";
}

/* =========================
   FILTER FILM BERDASARKAN GENRE
========================= */
void filterFilmByGenre() {
    cout << "\n====================================\n";
    cout << "       FILTER FILM BERDASARKAN GENRE\n";
    cout << "====================================\n";
    cout << "1. Action\n";
    cout << "2. Drama\n";
    cout << "3. Sci-Fi\n";
    cout << "4. Horror\n";
    cout << "5. Animation\n";
    cout << "6. Romance\n";
    cout << "====================================\n";
    cout << "Pilih Genre (1-6): ";
    int p;
    cin >> p;

    string genre;
    switch(p) {
        case 1: genre = "Action"; break;
        case 2: genre = "Drama"; break;
        case 3: genre = "Sci-Fi"; break;
        case 4: genre = "Horror"; break;
        case 5: genre = "Animation"; break;
        case 6: genre = "Romance"; break;
        default: genre = "Action"; break;
    }

    cout << "\n========== FILM " << genre << " ==========\n";
    bool ada = false;
    for(int i = 0; i < 20; i++) {
        if(film[i].genre == genre) {
            cout << film[i].idFilm << " | "
                 << film[i].judulFilm << "\t| "
                 << film[i].durasi << " mnt\t| "
                 << "Rp " << film[i].hargaTiket << endl;
            ada = true;
        }
    }
    if(!ada) {
        cout << "Tidak ada film dengan genre " << genre << ".\n";
    }
    cout << "==================================\n";
}

/* =========================
   FILTER FILM BERDASARKAN HARGA
========================= */
void filterFilmByHarga() {
    cout << "\n====================================\n";
    cout << "     FILTER FILM BERDASARKAN HARGA\n";
    cout << "====================================\n";
    double minHarga, maxHarga;
    cout << "Harga Minimum (Rp): ";
    cin >> minHarga;
    cout << "Harga Maksimum (Rp): ";
    cin >> maxHarga;

    cout << "\n==== FILM Rp" << minHarga << " - Rp" << maxHarga << " ====\n";
    bool ada = false;
    for(int i = 0; i < 20; i++) {
        if(film[i].hargaTiket >= minHarga && film[i].hargaTiket <= maxHarga) {
            cout << film[i].idFilm << " | "
                 << film[i].judulFilm << "\t| "
                 << film[i].genre << "\t| "
                 << "Rp " << film[i].hargaTiket << endl;
            ada = true;
        }
    }
    if(!ada) {
        cout << "Tidak ada film dalam rentang harga tersebut.\n";
    }
    cout << "==================================\n";
}

/* =========================
   CARI FILM BERDASARKAN JUDUL
========================= */
void cariFilmByJudul() {
    cout << "\n====================================\n";
    cout << "       CARI FILM BERDASARKAN JUDUL\n";
    cout << "====================================\n";
    cin.ignore();
    string kata;
    cout << "Masukkan kata kunci judul: ";
    getline(cin, kata);

    cout << "\n==== HASIL PENCARIAN: \"" << kata << "\" ====\n";
    bool ada = false;
    for(int i = 0; i < 20; i++) {
        // Cari substring sederhana (case sensitive)
        if(film[i].judulFilm.find(kata) != string::npos) {
            cout << film[i].idFilm << " | "
                 << film[i].judulFilm << " | "
                 << film[i].genre << " | "
                 << "Rp " << film[i].hargaTiket << endl;
            ada = true;
        }
    }
    if(!ada) {
        cout << "Film tidak ditemukan.\n";
    }
    cout << "==================================\n";
}

/* =========================
   CLASS RIWAYAT TRANSAKSI
========================= */
class RiwayatTransaksi {
public:
    string kodeTransaksi;
    string namaPelanggan;
    string judulFilm;
    string idFilm;
    int jumlahTiket;
    double totalBayar;
    string metodeBayar;
    string tanggalTransaksi;
    bool adaSnack;
    double totalSnack;

    RiwayatTransaksi() {
        kodeTransaksi = "";
        namaPelanggan = "";
        judulFilm = "";
        idFilm = "";
        jumlahTiket = 0;
        totalBayar = 0;
        metodeBayar = "";
        tanggalTransaksi = "";
        adaSnack = false;
        totalSnack = 0;
    }

    void tampil() {
        cout << "-----------------------------------\n";
        cout << "Kode TRX   : " << kodeTransaksi << endl;
        cout << "Pelanggan  : " << namaPelanggan << endl;
        cout << "Film       : " << judulFilm << endl;
        cout << "Tiket      : " << jumlahTiket << " lembar" << endl;
        cout << "Total Tiket: Rp " << totalBayar << endl;
        if(adaSnack) {
            cout << "Total Snack: Rp " << totalSnack << endl;
            cout << "Total Grand: Rp " << totalBayar + totalSnack << endl;
        }
        cout << "Metode     : " << metodeBayar << endl;
        cout << "Tanggal    : " << tanggalTransaksi << endl;
    }
};

/* =========================
   DATA RIWAYAT TRANSAKSI GLOBAL
========================= */
RiwayatTransaksi riwayat[100];
int jumlahRiwayat = 0;
int nomorTransaksi = 1;

// Simpan transaksi ke riwayat
void simpanRiwayat(string nama, string judulFilm, string idFilm,
                   int jumlahTiket, double totalBayar,
                   string metode, string tanggal,
                   bool adaSnack, double totalSnack) {
    if(jumlahRiwayat >= 100) return;

    RiwayatTransaksi r;

    // Generate kode transaksi
    string nomStr = to_string(nomorTransaksi);
    while(nomStr.length() < 3) nomStr = "0" + nomStr;
    r.kodeTransaksi     = "TRX" + nomStr;
    nomorTransaksi++;

    r.namaPelanggan     = nama;
    r.judulFilm         = judulFilm;
    r.idFilm            = idFilm;
    r.jumlahTiket       = jumlahTiket;
    r.totalBayar        = totalBayar;
    r.metodeBayar       = metode;
    r.tanggalTransaksi  = tanggal;
    r.adaSnack          = adaSnack;
    r.totalSnack        = totalSnack;

    riwayat[jumlahRiwayat] = r;
    jumlahRiwayat++;
}

// Tampilkan semua riwayat transaksi
void tampilRiwayatTransaksi() {
    cout << "\n====================================\n";
    cout << "       RIWAYAT TRANSAKSI\n";
    cout << "====================================\n";
    if(jumlahRiwayat == 0) {
        cout << "Belum ada transaksi.\n";
    } else {
        for(int i = 0; i < jumlahRiwayat; i++) {
            riwayat[i].tampil();
        }
    }
    cout << "====================================\n";
}

/* =========================
   LAPORAN STATISTIK LANJUTAN
========================= */
void tampilLaporanLanjutan() {
    cout << "\n====================================\n";
    cout << "       LAPORAN STATISTIK LANJUTAN\n";
    cout << "====================================\n";

    if(jumlahRiwayat == 0) {
        cout << "Belum ada data transaksi.\n";
        cout << "====================================\n";
        return;
    }

    int totalTiket = 0;
    double totalPendapatan = 0;
    double totalPendapatanSnack = 0;
    int transaksiSnack = 0;

    // Hitung per genre
    string genres[] = {"Action","Drama","Sci-Fi","Horror","Animation","Romance"};
    int tiketPerGenre[6] = {0,0,0,0,0,0};
    double pendapatanPerGenre[6] = {0,0,0,0,0,0};

    // Hitung per metode bayar
    string metodes[] = {"Cash","Debit","QRIS"};
    int countMetode[3] = {0,0,0};

    for(int i = 0; i < jumlahRiwayat; i++) {
        totalTiket += riwayat[i].jumlahTiket;
        totalPendapatan += riwayat[i].totalBayar;
        if(riwayat[i].adaSnack) {
            totalPendapatanSnack += riwayat[i].totalSnack;
            transaksiSnack++;
        }

        // Cari genre film
        for(int j = 0; j < 20; j++) {
            if(film[j].idFilm == riwayat[i].idFilm) {
                for(int k = 0; k < 6; k++) {
                    if(film[j].genre == genres[k]) {
                        tiketPerGenre[k] += riwayat[i].jumlahTiket;
                        pendapatanPerGenre[k] += riwayat[i].totalBayar;
                    }
                }
            }
        }

        // Metode bayar
        for(int m = 0; m < 3; m++) {
            if(riwayat[i].metodeBayar == metodes[m]) {
                countMetode[m]++;
            }
        }
    }

    cout << "Total Transaksi      : " << jumlahRiwayat << endl;
    cout << "Total Tiket Terjual  : " << totalTiket << endl;
    cout << "Total Pendapatan     : Rp " << totalPendapatan << endl;
    cout << "Total Snack          : Rp " << totalPendapatanSnack << endl;
    cout << "Grand Total          : Rp " << totalPendapatan + totalPendapatanSnack << endl;
    cout << "\n--- Tiket per Genre ---\n";
    for(int k = 0; k < 6; k++) {
        if(tiketPerGenre[k] > 0) {
            cout << genres[k] << "\t: "
                 << tiketPerGenre[k] << " tiket"
                 << " | Rp " << pendapatanPerGenre[k] << endl;
        }
    }
    cout << "\n--- Metode Pembayaran ---\n";
    for(int m = 0; m < 3; m++) {
        cout << metodes[m] << "\t: " << countMetode[m] << " transaksi" << endl;
    }
    cout << "====================================\n";
}

/* =========================
   VOUCHER / PROMO
========================= */
class Voucher {
public:
    string kodeVoucher;
    string deskripsi;
    double diskonPersen; // 0.0 - 1.0
    double diskonNominal;
    double minBelanjaVoucher;
    bool aktif;
};

Voucher daftarVoucher[10] = {
    {"CGVNEW","Diskon 10% untuk member baru",0.10,0,0,true},
    {"CGVWEEKEND","Diskon 15% pembelian weekend",0.15,0,100000,true},
    {"CGVFLASH","Flash sale Rp20.000",0.0,20000,50000,true},
    {"CGVHOROR","Diskon 20% film Horror",0.20,0,80000,true},
    {"CGVFAMILY","Diskon 5% untuk 3 tiket atau lebih",0.05,0,120000,true},
    {"CGVBDAY","Birthday voucher Rp50.000",0.0,50000,0,true},
    {"CGVSCI","Diskon 12% film Sci-Fi",0.12,0,90000,true},
    {"CGVSNACK","Diskon snack 25%",0.25,0,0,true},
    {"CGVPREM","Diskon 8% weekend malam",0.08,0,150000,true},
    {"CGVGOLD","Diskon 18% member Gold",0.18,0,0,false}
};

// Tampilkan daftar voucher
void tampilDaftarVoucher() {
    cout << "\n====================================\n";
    cout << "         DAFTAR VOUCHER CGV\n";
    cout << "====================================\n";
    for(int i = 0; i < 10; i++) {
        if(daftarVoucher[i].aktif) {
            cout << daftarVoucher[i].kodeVoucher << " | "
                 << daftarVoucher[i].deskripsi << endl;
        }
    }
    cout << "====================================\n";
}

// Terapkan voucher ke total harga
double terapkanVoucher(double total, bool &voucherDigunakan) {
    tampilDaftarVoucher();
    string kode;
    cout << "Masukkan kode voucher (atau '0' untuk skip): ";
    cin >> kode;

    if(kode == "0") {
        voucherDigunakan = false;
        return total;
    }

    for(int i = 0; i < 10; i++) {
        if(daftarVoucher[i].kodeVoucher == kode && daftarVoucher[i].aktif) {
            if(total < daftarVoucher[i].minBelanjaVoucher) {
                cout << "[!] Minimum belanja tidak terpenuhi (min Rp "
                     << daftarVoucher[i].minBelanjaVoucher << ")\n";
                voucherDigunakan = false;
                return total;
            }
            double diskon = 0;
            if(daftarVoucher[i].diskonPersen > 0) {
                diskon = total * daftarVoucher[i].diskonPersen;
            } else {
                diskon = daftarVoucher[i].diskonNominal;
            }
            double totalBaru = total - diskon;
            if(totalBaru < 0) totalBaru = 0;
            cout << "[SUKSES] Voucher berhasil diterapkan!\n";
            cout << "Diskon     : Rp " << diskon << endl;
            cout << "Total Baru : Rp " << totalBaru << endl;
            voucherDigunakan = true;
            // Nonaktifkan voucher sekali pakai
            daftarVoucher[i].aktif = false;
            return totalBaru;
        }
    }

    cout << "[!] Kode voucher tidak valid atau sudah digunakan.\n";
    voucherDigunakan = false;
    return total;
}

/* =========================
   CLASS ANTRIAN / QUEUE TIKET
========================= */
class AntrianTiket {
public:
    string namaAntrian[20];
    int depan;
    int belakang;
    int jumlah;

    AntrianTiket() {
        depan = 0;
        belakang = -1;
        jumlah = 0;
    }

    bool kosong() { return jumlah == 0; }
    bool penuh()  { return jumlah == 20; }

    void enqueue(string nama) {
        if(penuh()) {
            cout << "[!] Antrian penuh!\n";
            return;
        }
        belakang = (belakang + 1) % 20;
        namaAntrian[belakang] = nama;
        jumlah++;
        cout << "[+] " << nama << " berhasil masuk antrian (posisi " << jumlah << ")\n";
    }

    string dequeue() {
        if(kosong()) {
            cout << "[!] Antrian kosong!\n";
            return "";
        }
        string nama = namaAntrian[depan];
        depan = (depan + 1) % 20;
        jumlah--;
        return nama;
    }

    void tampilAntrian() {
        cout << "\n====================================\n";
        cout << "          ANTRIAN PEMBELIAN TIKET\n";
        cout << "====================================\n";
        if(kosong()) {
            cout << "Antrian kosong.\n";
        } else {
            int idx = depan;
            for(int i = 0; i < jumlah; i++) {
                cout << i+1 << ". " << namaAntrian[idx] << endl;
                idx = (idx + 1) % 20;
            }
        }
        cout << "Jumlah antrian: " << jumlah << "\n";
        cout << "====================================\n";
    }
};

AntrianTiket antrianGlobal;

// Menu antrian
void menuAntrian() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "          MENU ANTRIAN\n";
        cout << "====================================\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Antrian Berikutnya\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: {
                cin.ignore();
                string nama;
                cout << "Nama pelanggan: ";
                getline(cin, nama);
                antrianGlobal.enqueue(nama);
                break;
            }
            case 2: {
                string dipanggil = antrianGlobal.dequeue();
                if(dipanggil != "") {
                    cout << "\n[PANGGILAN] Silakan maju ke loket: " << dipanggil << "\n";
                }
                break;
            }
            case 3: {
                antrianGlobal.tampilAntrian();
                break;
            }
            case 0: break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}

/* =========================
   INFORMASI BIOSKOP
========================= */
void tampilInfoBioskop() {
    cout << "\n====================================================\n";
    cout << "              INFORMASI CGV PAKUWON MALL\n";
    cout << "====================================================\n";
    cout << "Nama      : CGV Cinemas Pakuwon Mall Yogyakarta\n";
    cout << "Alamat    : Pakuwon Mall, Jl. Ring Road Utara,\n";
    cout << "            Condongcatur, Depok, Sleman,\n";
    cout << "            Daerah Istimewa Yogyakarta 55283\n";
    cout << "Telepon   : (0274) 123-4567\n";
    cout << "Email     : cgv.pakuwon@cgvcinemas.com\n";
    cout << "Website   : www.cgv.id\n";
    cout << "----------------------------------------------------\n";
    cout << "Jam Operasional:\n";
    cout << "  Senin - Jumat : 10.00 - 22.00 WIB\n";
    cout << "  Sabtu - Minggu: 09.00 - 23.00 WIB\n";
    cout << "----------------------------------------------------\n";
    cout << "Studio yang Tersedia:\n";
    cout << "  Studio 1  (Reguler)  - 100 kursi\n";
    cout << "  Studio 2  (Reguler)  - 100 kursi\n";
    cout << "  Studio 3  (Reguler)  - 100 kursi\n";
    cout << "  Studio 4  (4DX)      -  80 kursi\n";
    cout << "  Studio 5  (IMAX)     - 120 kursi\n";
    cout << "  Studio 6  (Sweetbox) -  40 kursi\n";
    cout << "----------------------------------------------------\n";
    cout << "Fasilitas:\n";
    cout << "  - Parkir luas (gratis 2 jam pertama)\n";
    cout << "  - Konter snack & minuman\n";
    cout << "  - Layanan disabilitas\n";
    cout << "  - WiFi gratis di area lobi\n";
    cout << "  - ATM / EDC tersedia\n";
    cout << "====================================================\n";
}

/* =========================
   PERATURAN BIOSKOP
========================= */
void tampilPeraturanBioskop() {
    cout << "\n====================================================\n";
    cout << "            PERATURAN CGV CINEMAS\n";
    cout << "====================================================\n";
    cout << "1. Tiket yang sudah dibeli tidak dapat dikembalikan\n";
    cout << "   atau ditukar kecuali film dibatalkan oleh pihak\n";
    cout << "   bioskop.\n";
    cout << "2. Dilarang merekam atau memfoto film yang sedang\n";
    cout << "   diputar. Pelanggaran dapat dikenakan sanksi\n";
    cout << "   hukum sesuai UU Hak Cipta.\n";
    cout << "3. Matikan atau silent-kan ponsel selama film\n";
    cout << "   berlangsung.\n";
    cout << "4. Dilarang membawa makanan dan minuman dari luar\n";
    cout << "   ke dalam studio.\n";
    cout << "5. Anak di bawah 3 tahun tidak dikenakan biaya\n";
    cout << "   tiket namun tidak mendapatkan kursi.\n";
    cout << "6. Penonton wajib menempati kursi sesuai tiket.\n";
    cout << "7. Penonton dengan kebutuhan khusus harap\n";
    cout << "   menghubungi petugas.\n";
    cout << "8. Rating film wajib diperhatikan:\n";
    cout << "   - SU  : Semua Umur\n";
    cout << "   - 13+ : 13 tahun ke atas\n";
    cout << "   - 17+ : 17 tahun ke atas\n";
    cout << "   - 21+ : 21 tahun ke atas (khusus film dewasa)\n";
    cout << "9. CGV berhak menolak penonton yang tidak sesuai\n";
    cout << "   dengan rating film.\n";
    cout << "10. Jagalah kebersihan dan ketertiban bioskop.\n";
    cout << "====================================================\n";
}

/* =========================
   JADWAL TAYANG (HARDCODED)
========================= */
void tampilJadwalTayang() {
    cout << "\n====================================================================\n";
    cout << "                     JADWAL TAYANG HARI INI\n";
    cout << "====================================================================\n";

    // Struktur sederhana untuk jadwal
    struct JadwalFilm {
        string judulFilm;
        string studio;
        string jam1;
        string jam2;
        string jam3;
    };

    JadwalFilm jadwal[] = {
        {"Avengers Endgame",  "Studio 5 (IMAX)", "10:00","14:00","18:00"},
        {"Spider-Man NWH",    "Studio 1",        "11:00","15:00","19:00"},
        {"The Batman",        "Studio 2",        "10:30","14:30","18:30"},
        {"Interstellar",      "Studio 3",        "12:00","16:00","20:00"},
        {"The Nun",           "Studio 1",        "13:00","17:00","21:00"},
        {"Minions",           "Studio 4 (4DX)",  "10:00","13:00","16:00"},
        {"Joker",             "Studio 2",        "11:30","15:30","19:30"},
        {"John Wick 4",       "Studio 3",        "12:30","16:30","20:30"}
    };

    cout << left;
    cout << setw(22) << "Film"
         << setw(18) << "Studio"
         << setw(8) << "Jam 1"
         << setw(8) << "Jam 2"
         << "Jam 3" << endl;
    cout << "--------------------------------------------------------------------\n";

    for(int i = 0; i < 8; i++) {
        cout << setw(22) << jadwal[i].judulFilm
             << setw(18) << jadwal[i].studio
             << setw(8) << jadwal[i].jam1
             << setw(8) << jadwal[i].jam2
             << jadwal[i].jam3 << endl;
    }

    cout << "====================================================================\n";
}

/* =========================
   KONVERSI DURASI
========================= */
void tampilDurasiFilm() {
    cout << "\n====================================\n";
    cout << "       DURASI SEMUA FILM\n";
    cout << "====================================\n";
    cout << left;
    cout << setw(5)  << "ID"
         << setw(22) << "Judul Film"
         << setw(8)  << "Menit"
         << "Jam : Menit" << endl;
    cout << "------------------------------------\n";
    for(int i = 0; i < 20; i++) {
        int jam  = film[i].durasi / 60;
        int mnt  = film[i].durasi % 60;
        cout << setw(5)  << film[i].idFilm
             << setw(22) << film[i].judulFilm
             << setw(8)  << film[i].durasi
             << jam << " jam " << mnt << " menit" << endl;
    }
    cout << "====================================\n";
}

/* =========================
   MENU INFORMASI FILM
========================= */
void menuInfoFilm() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "         MENU INFORMASI FILM\n";
        cout << "====================================\n";
        cout << "1. Daftar Semua Film\n";
        cout << "2. Filter Film per Genre\n";
        cout << "3. Filter Film per Harga\n";
        cout << "4. Cari Film (Judul)\n";
        cout << "5. Durasi Film\n";
        cout << "6. Jadwal Tayang Hari Ini\n";
        cout << "7. Tampilkan Ulasan Film\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampilDaftarFilm(); break;
            case 2: filterFilmByGenre(); break;
            case 3: filterFilmByHarga(); break;
            case 4: cariFilmByJudul(); break;
            case 5: tampilDurasiFilm(); break;
            case 6: tampilJadwalTayang(); break;
            case 7: {
                tampilDaftarFilm();
                string id;
                cout << "Masukkan ID film: ";
                cin >> id;
                tampilUlasanFilm(id);
                break;
            }
            case 0: break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}

/* =========================
   MENU MEMBER
========================= */
void menuMember() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "           MENU MEMBER CGV\n";
        cout << "====================================\n";
        cout << "1. Daftar Member Baru\n";
        cout << "2. Cari Member\n";
        cout << "3. Tampilkan Semua Member\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: {
                daftarMemberBaru();
                break;
            }
            case 2: {
                cin.ignore();
                string nama;
                cout << "Masukkan nama member: ";
                getline(cin, nama);
                Member* m = cariMemberByNama(nama);
                if(m != NULL) {
                    m->tampilMember();
                } else {
                    cout << "[!] Member tidak ditemukan.\n";
                }
                break;
            }
            case 3: {
                tampilSemuaMember();
                break;
            }
            case 0: break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}

/* =========================
   MENU LAPORAN
========================= */
void menuLaporan() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "          MENU LAPORAN\n";
        cout << "====================================\n";
        cout << "1. Riwayat Transaksi\n";
        cout << "2. Laporan Statistik\n";
        cout << "3. Semua Ulasan Film\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampilRiwayatTransaksi(); break;
            case 2: tampilLaporanLanjutan(); break;
            case 3: tampilSemuaUlasan(); break;
            case 0: break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}

/* =========================
   PROSES PEMBELIAN TIKET
   (Refactored dari main lama,
    semua fitur asli dipertahankan)
========================= */
void prosesPembelianTiket() {

    // ---- FITUR ASLI (tidak diubah) ----

    // Menampilkan daftar film
    tampilDaftarFilm();

    // Memilih film
    Film f = pilihFilm();
    inisialisasiKursi();

    // Membuat studio
    Studio s;
    s.kodeStudio = "S03";
    s.namaStudio = "Audi 3";
    s.kapasitas = 100;

    // Membuat jadwal
    Jadwal j;
    j.tanggal = "25 April 2026";
    j.jamMulai = "18:20";
    j.jamSelesai = "20:44";

    // Membuat tiket
    Tiket t;

    t.harga = f.hargaTiket;
    cout << "Harga : Rp " << t.harga << endl;
    t.judulFilm = f.judulFilm;
    t.durasi = f.durasi;

    if(f.genre == "Animation")
        t.rating = "SU";
    else if(f.genre == "Horror")
        t.rating = "17+";
    else
        t.rating = "13+";

    t.lokasi = "Pakuwon Mall Jogja";
    t.tanggal = 25;
    t.bulan = 4;
    t.tahun = 2026;

    t.waktuMulai = 18;
    t.waktuSelesai = 21;
    t.studio = s.namaStudio;
    pilihKursi(t);

    // Menampilkan tiket
    t.output();

    // Pembayaran
    Pembayaran p;
    int metode;

    cout << "\n===== PEMBAYARAN =====" << endl;
    cout << "1. Cash" << endl;
    cout << "2. Debit" << endl;
    cout << "3. QRIS" << endl;

    cout << "Pilih : ";
    cin >> metode;

    switch(metode) {
        case 1: p.metode = "Cash"; break;
        case 2: p.metode = "Debit"; break;
        case 3: p.metode = "QRIS"; break;
        default: p.metode = "Cash"; break;
    }

    p.totalBayar = f.hargaTiket * t.jumlahTiket;
    p.tampilPembayaran();

    // Transaksi
    Transaksi tr;
    tr.kodeTransaksi = "TRX001";
    tr.namaPelanggan = "Adimza";
    tr.dataFilm = f;
    tr.bayar = p;
    tr.tampilTransaksi();

    // Laporan
    Laporan l;
    l.totalTiket = t.jumlahTiket;
    l.totalPendapatan = p.totalBayar;
    l.tampilLaporan();

    // ---- FITUR BARU TAMBAHAN ----

    // Tanya snack
    double totalSnack = 0;
    bool adaSnack = false;
    PesananSnack pesananSnack[10];
    int jumlahPesananSnack = 0;

    char mauSnack;
    cout << "\nApakah ingin memesan snack? (y/n): ";
    cin >> mauSnack;
    if(mauSnack == 'y' || mauSnack == 'Y') {
        pesanSnack(pesananSnack, jumlahPesananSnack, totalSnack);
        tampilPesananSnack(pesananSnack, jumlahPesananSnack, totalSnack);
        adaSnack = (jumlahPesananSnack > 0);
    }

    // Tanya voucher
    double grandTotal = p.totalBayar + totalSnack;
    bool voucherDigunakan = false;

    char mauVoucher;
    cout << "\nApakah punya kode voucher? (y/n): ";
    cin >> mauVoucher;
    if(mauVoucher == 'y' || mauVoucher == 'Y') {
        grandTotal = terapkanVoucher(grandTotal, voucherDigunakan);
    }

    // Ringkasan total akhir
    cout << "\n====================================\n";
    cout << "           RINGKASAN AKHIR\n";
    cout << "====================================\n";
    cout << "Total Tiket  : Rp " << p.totalBayar << endl;
    if(adaSnack)
        cout << "Total Snack  : Rp " << totalSnack << endl;
    if(voucherDigunakan)
        cout << "[VOUCHER DIGUNAKAN]\n";
    cout << "GRAND TOTAL  : Rp " << grandTotal << endl;
    cout << "====================================\n";

    // Simpan ke riwayat
    simpanRiwayat(
        tr.namaPelanggan,
        f.judulFilm,
        f.idFilm,
        t.jumlahTiket,
        p.totalBayar,
        p.metode,
        "25/04/2026",
        adaSnack,
        totalSnack
    );

    // Tanya ulasan
    char mauUlasan;
    cout << "\nApakah ingin memberikan ulasan film? (y/n): ";
    cin >> mauUlasan;
    if(mauUlasan == 'y' || mauUlasan == 'Y') {
        inputUlasan(f.idFilm, f.judulFilm, tr.namaPelanggan);
    }

    // Tambah poin member jika sudah terdaftar
    Member* m = cariMemberByNama(tr.namaPelanggan);
    if(m != NULL) {
        cout << "\n[MEMBER] Menambahkan poin untuk " << m->nama << "...\n";
        m->tambahPoin(grandTotal);
        m->tampilMember();
    } else {
        cout << "\n[INFO] Daftar sebagai member untuk mendapatkan poin!\n";
    }

    cout << "\n[INFO] Terima kasih sudah menonton di CGV!\n";
    cout << "[INFO] Selamat menikmati film " << f.judulFilm << "!\n";
}


/* =========================
   SINOPSIS FILM
========================= */
void tampilSinopsisFilm() {
    tampilDaftarFilm();
    string id;
    cout << "\nMasukkan ID Film untuk melihat sinopsis: ";
    cin >> id;

    // Sinopsis hardcoded untuk beberapa film populer
    if(id == "F01") {
        cout << "\n=== Avengers: Endgame (2019) ===\n";
        cout << "Genre   : Action / Sci-Fi\n";
        cout << "Durasi  : 181 menit\n";
        cout << "Rating  : 13+\n";
        cout << "Sutradara: Anthony & Joe Russo\n";
        cout << "\nSinopsis:\n";
        cout << "Setelah Thanos berhasil mengumpulkan semua Infinity Stone\n";
        cout << "dan melenyapkan setengah populasi semesta, para Avengers\n";
        cout << "yang tersisa bersatu untuk satu misi terakhir yang penuh\n";
        cout << "pengorbanan. Dengan bantuan Ant-Man yang menemukan cara\n";
        cout << "melewati waktu melalui Quantum Realm, mereka berencana\n";
        cout << "untuk mengumpulkan kembali semua Infinity Stone dari masa\n";
        cout << "lalu dan membalikkan apa yang telah Thanos lakukan.\n";
        cout << "Film ini merupakan puncak dari 22 film Marvel Cinematic\n";
        cout << "Universe yang telah dibangun selama lebih dari 10 tahun.\n";
    } else if(id == "F05") {
        cout << "\n=== Interstellar (2014) ===\n";
        cout << "Genre   : Sci-Fi / Drama\n";
        cout << "Durasi  : 169 menit\n";
        cout << "Rating  : 13+\n";
        cout << "Sutradara: Christopher Nolan\n";
        cout << "\nSinopsis:\n";
        cout << "Di masa depan, Bumi menghadapi kelaparan massal dan\n";
        cout << "kepunahan akibat bencana ekologi. Seorang mantan pilot\n";
        cout << "NASA bernama Cooper terpilih memimpin misi melewati\n";
        cout << "lubang cacing dekat Saturnus untuk menemukan planet\n";
        cout << "baru yang layak huni bagi manusia. Perjalanan antar\n";
        cout << "galaksi ini penuh dengan paradoks waktu, relativitas,\n";
        cout << "dan dilema moral antara keselamatan umat manusia\n";
        cout << "versus kesetiaan kepada keluarga yang ditinggalkan.\n";
    } else if(id == "F06") {
        cout << "\n=== Inception (2010) ===\n";
        cout << "Genre   : Sci-Fi / Thriller\n";
        cout << "Durasi  : 148 menit\n";
        cout << "Rating  : 13+\n";
        cout << "Sutradara: Christopher Nolan\n";
        cout << "\nSinopsis:\n";
        cout << "Dom Cobb adalah pencuri handal yang ahli dalam seni\n";
        cout << "inception, yaitu masuk ke dalam mimpi seseorang untuk\n";
        cout << "mencuri atau menanamkan ide. Ia ditawari satu kesempatan\n";
        cout << "untuk membersihkan namanya: bukan mencuri ide, tapi\n";
        cout << "menanamkan satu. Untuk melakukan ini, ia harus masuk\n";
        cout << "ke lapisan mimpi terdalam, sebuah wilayah yang penuh\n";
        cout << "dengan rahasia dan bahaya yang tak terduga.\n";
    } else if(id == "F04") {
        cout << "\n=== Joker (2019) ===\n";
        cout << "Genre   : Drama / Thriller\n";
        cout << "Durasi  : 122 menit\n";
        cout << "Rating  : 17+\n";
        cout << "Sutradara: Todd Phillips\n";
        cout << "\nSinopsis:\n";
        cout << "Arthur Fleck adalah seorang pria yang berjuang dengan\n";
        cout << "gangguan mental dan hidup di tengah masyarakat Gotham\n";
        cout << "yang penuh ketidakadilan. Ia bekerja sebagai badut harian\n";
        cout << "sambil bermimpi menjadi komedian stand-up. Setelah\n";
        cout << "serangkaian peristiwa tragis, Arthur perlahan\n";
        cout << "bertransformasi menjadi sosok Joker yang ikonik.\n";
        cout << "Film ini meraih Penghargaan Golden Lion di Venice.\n";
    } else if(id == "F19") {
        cout << "\n=== Parasite (2019) ===\n";
        cout << "Genre   : Drama / Thriller\n";
        cout << "Durasi  : 132 menit\n";
        cout << "Rating  : 17+\n";
        cout << "Sutradara: Bong Joon-ho\n";
        cout << "\nSinopsis:\n";
        cout << "Keluarga Kim yang miskin perlahan-lahan menyusup ke\n";
        cout << "kehidupan keluarga kaya Park dengan berpura-pura memiliki\n";
        cout << "keahlian yang tidak mereka miliki. Apa yang dimulai\n";
        cout << "sebagai rencana cerdas berubah menjadi sebuah situasi\n";
        cout << "yang semakin kompleks dan berbahaya. Film Korea pertama\n";
        cout << "yang memenangkan Oscar untuk Film Terbaik (2020).\n";
    } else {
        cout << "\n[INFO] Sinopsis untuk film " << id << " belum tersedia.\n";
        cout << "       Silakan kunjungi website CGV untuk detail lebih lanjut.\n";
    }
    cout << "====================================\n";
}

/* =========================
   STRUK PEMBELIAN
========================= */
void cetakStruk(string namaPelanggan, string judulFilm,
                int jumlahTiket, double hargaTiket,
                double totalSnack, double grandTotal,
                string metodeBayar, string tanggal) {

    cout << "\n";
    cout << "========================================\n";
    cout << "          CGV CINEMAS\n";
    cout << "       Pakuwon Mall Yogyakarta\n";
    cout << "========================================\n";
    cout << "Jl. Ring Road Utara, Sleman, DIY\n";
    cout << "Telp: (0274) 123-4567\n";
    cout << "----------------------------------------\n";
    cout << "STRUK PEMBELIAN TIKET\n";
    cout << "Tanggal   : " << tanggal << "\n";
    cout << "Kasir     : Admin CGV\n";
    cout << "Pelanggan : " << namaPelanggan << "\n";
    cout << "----------------------------------------\n";
    cout << "DETAIL PEMBELIAN\n";
    cout << "Film      : " << judulFilm << "\n";
    cout << left << setw(20) << "Tiket Bioskop";
    cout << right << setw(18) << "Rp " + to_string((int)hargaTiket) << "\n";
    if(jumlahTiket > 1) {
        cout << "  x " << jumlahTiket << " tiket\n";
    }
    cout << left << setw(20) << "Subtotal Tiket";
    cout << right << setw(18) << "Rp " + to_string((int)(hargaTiket * jumlahTiket)) << "\n";
    if(totalSnack > 0) {
        cout << left << setw(20) << "Snack & Minuman";
        cout << right << setw(18) << "Rp " + to_string((int)totalSnack) << "\n";
    }
    cout << "----------------------------------------\n";
    cout << left << setw(20) << "TOTAL BAYAR";
    cout << right << setw(18) << "Rp " + to_string((int)grandTotal) << "\n";
    cout << left << setw(20) << "Metode Bayar";
    cout << right << setw(18) << metodeBayar << "\n";
    cout << "========================================\n";
    cout << "  Terima kasih telah memilih CGV!\n";
    cout << "  Selamat menikmati film Anda.\n";
    cout << "  Simpan struk ini sebagai bukti.\n";
    cout << "========================================\n";
    cout << "\n";
}

/* =========================
   MENU INFO TAMBAHAN (diperbarui)
========================= */
void menuInfoTambahan() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "         MENU INFORMASI LAINNYA\n";
        cout << "====================================\n";
        cout << "1. Sinopsis Film\n";
        cout << "2. Daftar Voucher Tersedia\n";
        cout << "3. Jadwal Tayang\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampilSinopsisFilm(); break;
            case 2: tampilDaftarVoucher(); break;
            case 3: tampilJadwalTayang(); break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}


/* =====================================================
   CATATAN PENGEMBANGAN & STRUKTUR PROGRAM
   =====================================================
   
   Program ini adalah Sistem Penjualan Tiket Bioskop
   CGV Cinemas yang dikembangkan menggunakan C++
   dengan pendekatan Object-Oriented Programming (OOP).
   
   DAFTAR CLASS YANG DIGUNAKAN:
   -------------------------------------------------------
   1.  Film          - Menyimpan data film (ID, judul,
                       genre, durasi, harga tiket).
   
   2.  Tiket         - Menyimpan data tiket yang dibeli
                       (film, kursi, jadwal, harga).
   
   3.  Kursi         - Merepresentasikan satu kursi di
                       studio dengan kode dan status.
   
   4.  Studio        - Data studio (kode, nama, kapasitas).
   
   5.  Jadwal        - Jadwal tayang (tanggal, jam mulai,
                       jam selesai).
   
   6.  Genre         - Informasi genre film.
   
   7.  Pembayaran    - Data pembayaran (metode, total).
   
   8.  Transaksi     - Gabungan data pelanggan, film,
                       dan pembayaran dalam satu transaksi.
   
   9.  Laporan       - Ringkasan total tiket dan pendapatan.
   
   10. Member        - Data member dengan poin dan level.
   
   11. Snack         - Item menu makanan dan minuman.
   
   12. Ulasan        - Review film dari penonton.
   
   13. Voucher       - Kode diskon yang bisa digunakan.
   
   14. RiwayatTransaksi - Log semua transaksi yang terjadi.
   
   15. AntrianTiket  - Sistem antrian dengan struktur Queue.
   
   DAFTAR FUNGSI UTAMA:
   -------------------------------------------------------
   - inisialisasiKursi() : Inisialisasi 100 kursi (A01-J10)
   - tampilKursi()       : Tampilkan peta kursi visual
   - pilihKursi()        : Input pilihan kursi penonton
   - tampilDaftarFilm()  : Tabel semua film tersedia
   - pilihFilm()         : Menu interaktif pilih film
   - cariFilm()          : Cari film berdasarkan ID
   - filterFilmByGenre() : Filter film berdasarkan genre
   - filterFilmByHarga() : Filter film berdasarkan harga
   - cariFilmByJudul()   : Pencarian film berdasarkan judul
   - daftarMemberBaru()  : Pendaftaran member baru
   - cariMemberByNama()  : Cari member berdasarkan nama
   - pesanSnack()        : Proses pemesanan snack
   - tampilMenuSnack()   : Tampilkan daftar snack
   - inputUlasan()       : Input ulasan film dari penonton
   - tampilUlasanFilm()  : Tampilkan ulasan per film
   - terapkanVoucher()   : Proses penggunaan kode voucher
   - simpanRiwayat()     : Simpan transaksi ke riwayat
   - tampilRiwayatTransaksi() : Tampilkan semua riwayat
   - tampilLaporanLanjutan()  : Statistik penjualan detail
   - cetakStruk()        : Cetak struk pembelian
   - tampilJadwalTayang(): Jadwal tayang hari ini
   - rekomendasiFilm()   : Rekomendasi film berdasarkan preferensi
   - kalkulatorHarga()   : Simulasi perhitungan harga tiket
   - tampilSinopsisFilm(): Sinopsis detail per film
   - menuAntrian()       : Manajemen antrian pelanggan
   
   STRUKTUR MENU:
   -------------------------------------------------------
   MENU UTAMA
   |-- 1. Beli Tiket
   |      |-- Pilih Film
   |      |-- Pilih Kursi
   |      |-- Detail Tiket
   |      |-- Pembayaran
   |      |-- Pesan Snack
   |      |-- Gunakan Voucher
   |      |-- Struk & Riwayat
   |      `-- Ulasan Film
   |
   |-- 2. Informasi Film
   |      |-- Daftar Semua Film
   |      |-- Filter Genre
   |      |-- Filter Harga
   |      |-- Cari Judul
   |      |-- Durasi Film
   |      |-- Jadwal Tayang
   |      `-- Ulasan Film
   |
   |-- 3. Menu Member
   |      |-- Daftar Member Baru
   |      |-- Cari Member
   |      `-- Daftar Semua Member
   |
   |-- 4. Menu Antrian
   |      |-- Tambah Antrian
   |      |-- Panggil Antrian
   |      `-- Tampilkan Antrian
   |
   |-- 5. Laporan & Statistik
   |      |-- Riwayat Transaksi
   |      |-- Laporan Statistik
   |      `-- Semua Ulasan Film
   |
   |-- 6. Informasi Bioskop
   |-- 7. Peraturan Bioskop
   |
   |-- 8. Bantuan & Panduan
   |      |-- Panduan Sistem
   |      |-- FAQ
   |      |-- Promo Aktif
   |      |-- Tips Menonton
   |      |-- Daftar Studio
   |      |-- Rekomendasi Film
   |      |-- Kalkulator Harga
   |      |-- Sinopsis Film
   |      `-- Daftar Voucher
   |
   |-- 9. Tentang Aplikasi
   `-- 0. Keluar
   
   =====================================================*/

/* =========================
   MENU UTAMA
========================= */
void tampilMenuUtama() {
    cout << "\n====================================================\n";
    cout << "           SELAMAT DATANG DI CGV CINEMAS\n";
    cout << "              Pakuwon Mall Yogyakarta\n";
    cout << "====================================================\n";
    cout << "1. Beli Tiket\n";
    cout << "2. Informasi Film\n";
    cout << "3. Menu Member\n";
    cout << "4. Menu Antrian\n";
    cout << "5. Laporan & Statistik\n";
    cout << "6. Informasi Bioskop\n";
    cout << "7. Peraturan Bioskop\n";
    cout << "8. Bantuan & Panduan\n";
    cout << "9. Tentang Aplikasi\n";
    cout << "0. Keluar\n";
    cout << "====================================================\n";
    cout << "Pilih menu: ";
}


/* =========================
   KALKULATOR HARGA TIKET
========================= */
void kalkulatorHarga() {
    cout << "\n====================================\n";
    cout << "       KALKULATOR HARGA TIKET\n";
    cout << "====================================\n";

    // Tampilkan semua film dan harga
    tampilDaftarFilm();

    string idFilm;
    cout << "Masukkan ID Film: ";
    cin >> idFilm;

    Film f = cariFilm(idFilm);

    int jumlah;
    cout << "Jumlah Tiket   : ";
    cin >> jumlah;

    if(jumlah < 1 || jumlah > 10) {
        cout << "[!] Jumlah tiket tidak valid (1-10).\n";
        return;
    }

    double subtotal = f.hargaTiket * jumlah;

    cout << "\n--- Simulasi Harga ---\n";
    cout << "Film           : " << f.judulFilm << "\n";
    cout << "Harga/Tiket    : Rp " << f.hargaTiket << "\n";
    cout << "Jumlah Tiket   : " << jumlah << "\n";
    cout << "Subtotal       : Rp " << subtotal << "\n";

    // Simulasi diskon member
    cout << "\n--- Simulasi Diskon Member ---\n";
    cout << "Regular (0%)   : Rp " << subtotal << "\n";
    cout << "Silver  (10%)  : Rp " << subtotal * 0.90 << "\n";
    cout << "Gold    (15%)  : Rp " << subtotal * 0.85 << "\n";
    cout << "Platinum(20%)  : Rp " << subtotal * 0.80 << "\n";

    cout << "====================================\n";
}

/* =========================
   REKOMENDASI FILM
========================= */
void rekomendasiFilm() {
    cout << "\n====================================\n";
    cout << "       REKOMENDASI FILM\n";
    cout << "====================================\n";
    cout << "Pilih preferensi Anda:\n";
    cout << "1. Film Action terbaik\n";
    cout << "2. Film untuk keluarga\n";
    cout << "3. Film menegangkan\n";
    cout << "4. Film dengan harga terjangkau\n";
    cout << "5. Film durasi pendek (< 2 jam)\n";
    cout << "6. Film durasi panjang (> 2 jam)\n";
    cout << "====================================\n";
    cout << "Pilih: ";

    int p;
    cin >> p;

    cout << "\n--- REKOMENDASI UNTUK ANDA ---\n";

    switch(p) {
        case 1:
            cout << "Film Action Terbaik:\n";
            cout << "  1. Avengers Endgame (F01) - Rp 50.000\n";
            cout << "     -> Klimaks epik 20+ film Marvel, wajib tonton!\n";
            cout << "  2. John Wick 4 (F20) - Rp 50.000\n";
            cout << "     -> Aksi non-stop dengan koreografi terbaik.\n";
            cout << "  3. The Batman (F03) - Rp 48.000\n";
            cout << "     -> Batman versi gelap dan psikologis.\n";
            break;
        case 2:
            cout << "Film untuk Keluarga:\n";
            cout << "  1. Minions (F12) - Rp 35.000\n";
            cout << "     -> Lucu dan cocok untuk semua usia!\n";
            cout << "  2. Frozen II (F13) - Rp 38.000\n";
            cout << "     -> Petualangan Elsa dan Anna yang mengagumkan.\n";
            cout << "  3. Moana (F14) - Rp 37.000\n";
            cout << "     -> Kisah semangat yang menginspirasi.\n";
            cout << "  4. Coco (F18) - Rp 36.000\n";
            cout << "     -> Film haru tentang keluarga dan mimpi.\n";
            break;
        case 3:
            cout << "Film Menegangkan:\n";
            cout << "  1. The Nun (F08) - Rp 40.000\n";
            cout << "     -> Teror biarawati dari semesta Conjuring.\n";
            cout << "  2. Annabelle (F09) - Rp 38.000\n";
            cout << "     -> Boneka paling menakutkan di dunia!\n";
            cout << "  3. Conjuring (F10) - Rp 42.000\n";
            cout << "     -> Kisah nyata yang bikin merinding.\n";
            break;
        case 4:
            cout << "Film Harga Terjangkau (< Rp 40.000):\n";
            cout << "  1. Minions (F12) - Rp 35.000\n";
            cout << "  2. Moana (F14) - Rp 37.000\n";
            cout << "  3. Coco (F18) - Rp 36.000\n";
            cout << "  4. Frozen II (F13) - Rp 38.000\n";
            cout << "  5. Annabelle (F09) - Rp 38.000\n";
            break;
        case 5:
            cout << "Film Durasi Pendek (< 120 menit):\n";
            cout << "  1. Minions (F12)    - 91 menit\n";
            cout << "  2. The Nun (F08)    - 96 menit\n";
            cout << "  3. Annabelle (F09)  - 99 menit\n";
            cout << "  4. Frozen II (F13)  - 103 menit\n";
            cout << "  5. Coco (F18)       - 105 menit\n";
            cout << "  6. Moana (F14)      - 107 menit\n";
            break;
        case 6:
            cout << "Film Durasi Panjang (> 120 menit):\n";
            cout << "  1. Titanic (F07)         - 195 menit\n";
            cout << "  2. Avengers Endgame (F01)- 181 menit\n";
            cout << "  3. The Batman (F03)      - 176 menit\n";
            cout << "  4. Interstellar (F05)    - 169 menit\n";
            cout << "  5. John Wick 4 (F20)     - 169 menit\n";
            break;
        default:
            cout << "[!] Pilihan tidak valid.\n";
    }

    cout << "====================================\n";
}

/* =========================
   PANDUAN PENGGUNAAN SISTEM
========================= */
void tampilPanduan() {
    cout << "\n====================================================\n";
    cout << "           PANDUAN PENGGUNAAN SISTEM\n";
    cout << "           CGV CINEMAS TICKETING\n";
    cout << "====================================================\n";

    cout << "\n[1] CARA MEMBELI TIKET\n";
    cout << "    - Pilih menu '1. Beli Tiket' dari menu utama.\n";
    cout << "    - Sistem akan menampilkan daftar 20 film tersedia.\n";
    cout << "    - Pilih film yang diinginkan (masukkan nomor 1-20).\n";
    cout << "    - Pilih kursi yang diinginkan dari peta kursi.\n";
    cout << "    - Konfirmasi detail tiket yang ditampilkan.\n";
    cout << "    - Pilih metode pembayaran (Cash/Debit/QRIS).\n";
    cout << "    - Tiket akan dicetak setelah pembayaran selesai.\n";

    cout << "\n[2] CARA MEMESAN SNACK\n";
    cout << "    - Setelah memilih tiket, sistem akan menanya\n";
    cout << "      apakah ingin memesan snack.\n";
    cout << "    - Ketik 'y' untuk memesan, 'n' untuk skip.\n";
    cout << "    - Pilih snack dari menu dengan kode (SK01-SK15).\n";
    cout << "    - Tentukan jumlah yang diinginkan.\n";
    cout << "    - Ketik '0' untuk selesai memesan snack.\n";

    cout << "\n[3] CARA MENGGUNAKAN VOUCHER\n";
    cout << "    - Setelah memesan snack, akan ada pilihan voucher.\n";
    cout << "    - Ketik 'y' lalu masukkan kode voucher.\n";
    cout << "    - Voucher hanya bisa digunakan sekali.\n";
    cout << "    - Pastikan total belanja memenuhi minimum voucher.\n";

    cout << "\n[4] SISTEM MEMBER\n";
    cout << "    - Daftar sebagai member untuk mendapat poin.\n";
    cout << "    - Setiap Rp 10.000 = 1 poin.\n";
    cout << "    - Level: Regular -> Silver(500) -> Gold(2000) -> Platinum(5000).\n";
    cout << "    - Member mendapat diskon otomatis sesuai level.\n";

    cout << "\n[5] KODE KURSI\n";
    cout << "    - Format: [Baris][Nomor], contoh: A01, B05, J10\n";
    cout << "    - Baris: A sampai J (10 baris)\n";
    cout << "    - Nomor: 01 sampai 10\n";
    cout << "    - Total 100 kursi per studio.\n";

    cout << "====================================================\n";
}

/* =========================
   FAQ (FREQUENTLY ASKED QUESTIONS)
========================= */
void tampilFAQ() {
    cout << "\n====================================================\n";
    cout << "          FAQ - PERTANYAAN YANG SERING DITANYA\n";
    cout << "====================================================\n";

    cout << "\nQ: Bisakah tiket dikembalikan?\n";
    cout << "A: Tiket yang sudah dibeli tidak dapat dikembalikan\n";
    cout << "   kecuali film dibatalkan oleh pihak bioskop.\n";

    cout << "\nQ: Berapa maksimal tiket yang bisa dibeli sekali transaksi?\n";
    cout << "A: Maksimal 10 tiket dalam satu kali transaksi.\n";

    cout << "\nQ: Apakah bisa memilih kursi yang berdekatan?\n";
    cout << "A: Ya, pilih satu per satu kode kursi yang berdekatan.\n";
    cout << "   Contoh: A01, A02, A03 untuk 3 kursi bersebelahan.\n";

    cout << "\nQ: Apa keuntungan menjadi member CGV?\n";
    cout << "A: Member mendapat poin dari setiap transaksi,\n";
    cout << "   dan diskon sesuai level (Silver 10%, Gold 15%,\n";
    cout << "   Platinum 20%).\n";

    cout << "\nQ: Apakah anak-anak perlu membeli tiket?\n";
    cout << "A: Anak di bawah 3 tahun gratis tanpa kursi.\n";
    cout << "   Anak 3 tahun ke atas wajib membeli tiket.\n";

    cout << "\nQ: Berapa lama sebelum film saya harus hadir?\n";
    cout << "A: Disarankan hadir 15-20 menit sebelum jadwal\n";
    cout << "   tayang untuk menghindari keramaian.\n";

    cout << "\nQ: Apakah bisa bayar pakai transfer bank?\n";
    cout << "A: Saat ini tersedia Cash, Debit, dan QRIS.\n";

    cout << "\nQ: Apa beda studio reguler, 4DX, dan IMAX?\n";
    cout << "A: - Reguler : Layar dan suara standar.\n";
    cout << "   - 4DX     : Kursi bergerak, angin, percikan air,\n";
    cout << "               aroma sesuai adegan film.\n";
    cout << "   - IMAX    : Layar raksasa dengan suara surround\n";
    cout << "               berkualitas sangat tinggi.\n";

    cout << "\nQ: Bagaimana cara menggunakan poin?\n";
    cout << "A: Poin bisa ditukarkan di loket atau melalui\n";
    cout << "   aplikasi CGV. 100 poin = Rp 5.000.\n";

    cout << "====================================================\n";
}

/* =========================
   PROMO AKTIF
========================= */
void tampilPromoAktif() {
    cout << "\n====================================================\n";
    cout << "              PROMO AKTIF CGV CINEMAS\n";
    cout << "====================================================\n";

    cout << "\n[PROMO 1] HAPPY TUESDAY\n";
    cout << "  Setiap hari Selasa, semua tiket diskon 30%!\n";
    cout << "  Berlaku untuk pembelian langsung di loket.\n";
    cout << "  *Tidak berlaku untuk studio IMAX dan 4DX.\n";

    cout << "\n[PROMO 2] CGV x BANK BCA\n";
    cout << "  Diskon 25% untuk pembayaran menggunakan\n";
    cout << "  Kartu Debit / Kredit BCA.\n";
    cout << "  Min. transaksi Rp 100.000.\n";
    cout << "  Berlaku Jumat-Minggu.\n";

    cout << "\n[PROMO 3] STUDENT PRICE\n";
    cout << "  Diskon 20% untuk pelajar / mahasiswa.\n";
    cout << "  Tunjukkan kartu pelajar/KTM yang masih berlaku.\n";
    cout << "  Berlaku setiap hari Senin-Kamis.\n";

    cout << "\n[PROMO 4] CGV x GOFOOD\n";
    cout << "  Pesan snack via GoFood dan dapatkan gratis\n";
    cout << "  1 cup soft drink ukuran medium!\n";
    cout << "  Berlaku untuk Combo A dan Combo B.\n";

    cout << "\n[PROMO 5] BIRTHDAY SPECIAL\n";
    cout << "  Di bulan ulang tahun Anda, dapatkan 1 tiket\n";
    cout << "  gratis untuk pembelian min. 2 tiket!\n";
    cout << "  Tunjukkan KTP / SIM sebagai bukti.\n";

    cout << "\n[PROMO 6] COUPLE WEEKEND\n";
    cout << "  Beli 2 tiket Sweetbox di hari Sabtu-Minggu,\n";
    cout << "  dapatkan 1 paket popcorn + 2 minuman gratis!\n";

    cout << "\n*Promo tidak dapat digabungkan kecuali disebutkan.\n";
    cout << "====================================================\n";
}

/* =========================
   TIPS MENONTON DI BIOSKOP
========================= */
void tampilTipsMenonton() {
    cout << "\n====================================================\n";
    cout << "           TIPS SERU MENONTON DI BIOSKOP\n";
    cout << "====================================================\n";

    cout << "\n1. PILIH KURSI TERBAIK\n";
    cout << "   Kursi terbaik biasanya berada di tengah-tengah\n";
    cout << "   studio (baris E atau F, nomor 4-7).\n";
    cout << "   Hindari kursi paling depan agar tidak pegal leher.\n";

    cout << "\n2. DATANG LEBIH AWAL\n";
    cout << "   Datanglah 15-20 menit sebelum jadwal tayang.\n";
    cout << "   Manfaatkan waktu untuk membeli snack dan mencari\n";
    cout << "   kursi yang nyaman.\n";

    cout << "\n3. MATIKAN / SILENT HP\n";
    cout << "   Dering HP sangat mengganggu penonton lain.\n";
    cout << "   Sebaiknya matikan HP atau ubah ke mode getar.\n";

    cout << "\n4. PILIH SNACK YANG TEPAT\n";
    cout << "   Hindari snack berbau tajam di dalam studio.\n";
    cout << "   Popcorn adalah pilihan klasik yang tidak mengganggu.\n";

    cout << "\n5. BERPAKAIAN NYAMAN\n";
    cout << "   Studio bioskop ber-AC. Bawa jaket tipis agar\n";
    cout << "   tidak kedinginan selama film berlangsung.\n";

    cout << "\n6. GUNAKAN MODE PESAWAT\n";
    cout << "   Mode pesawat mencegah notifikasi yang mengganggu\n";
    cout << "   sambil tetap bisa mengakses foto/kamera.\n";

    cout << "\n7. JAGA KEBERSIHAN\n";
    cout << "   Buang sampah snack pada tempatnya.\n";
    cout << "   Jaga kenyamanan bersama sesama penonton.\n";

    cout << "====================================================\n";
}

/* =========================
   DAFTAR STUDIO LENGKAP
========================= */
void tampilDaftarStudio() {
    cout << "\n====================================================\n";
    cout << "         DAFTAR STUDIO CGV PAKUWON MALL\n";
    cout << "====================================================\n";

    struct InfoStudio {
        string kode;
        string nama;
        string tipe;
        int kapasitas;
        string fasilitas;
        double hargaTambahan;
    };

    InfoStudio studios[] = {
        {"S01","Studio 1","Reguler",100,"Dolby Stereo, AC, Layar HD",0},
        {"S02","Studio 2","Reguler",100,"Dolby Stereo, AC, Layar HD",0},
        {"S03","Studio 3","Reguler",100,"Dolby Stereo, AC, Layar HD",0},
        {"S04","Studio 4","4DX",80,"Kursi Motion, Angin, Air, Aroma",50000},
        {"S05","Studio 5","IMAX",120,"Layar Raksasa, Dolby Atmos",30000},
        {"S06","Studio 6","Sweetbox",40,"Sofa Couple, AC Premium, Selimut",75000}
    };

    for(int i = 0; i < 6; i++) {
        cout << "\n[" << studios[i].kode << "] " << studios[i].nama
             << " (" << studios[i].tipe << ")\n";
        cout << "  Kapasitas  : " << studios[i].kapasitas << " kursi\n";
        cout << "  Fasilitas  : " << studios[i].fasilitas << "\n";
        if(studios[i].hargaTambahan > 0) {
            cout << "  Biaya Tambahan: +Rp " << studios[i].hargaTambahan << "/tiket\n";
        } else {
            cout << "  Biaya Tambahan: Gratis\n";
        }
    }

    cout << "\n====================================================\n";
}

/* =========================
   MENU BANTUAN
========================= */
void menuBantuan() {
    int pilih;
    do {
        cout << "\n====================================\n";
        cout << "          MENU BANTUAN\n";
        cout << "====================================\n";
        cout << "1. Panduan Penggunaan Sistem\n";
        cout << "2. FAQ\n";
        cout << "3. Promo Aktif\n";
        cout << "4. Tips Menonton\n";
        cout << "5. Daftar Studio\n";
        cout << "6. Rekomendasi Film\n";
        cout << "7. Kalkulator Harga\n";
        cout << "8. Sinopsis Film\n";
        cout << "9. Daftar Voucher\n";
        cout << "0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampilPanduan(); break;
            case 2: tampilFAQ(); break;
            case 3: tampilPromoAktif(); break;
            case 4: tampilTipsMenonton(); break;
            case 5: tampilDaftarStudio(); break;
            case 6: rekomendasiFilm(); break;
            case 7: kalkulatorHarga(); break;
            case 8: tampilSinopsisFilm(); break;
            case 9: tampilDaftarVoucher(); break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid!\n";
        }
    } while(pilih != 0);
}

/* =========================
   TENTANG APLIKASI
========================= */
void tampilTentangAplikasi() {
    cout << "\n====================================================\n";
    cout << "            TENTANG APLIKASI\n";
    cout << "====================================================\n";
    cout << "Nama Aplikasi : CGV Cinemas Ticketing System\n";
    cout << "Versi         : 2.0.0\n";
    cout << "Dibuat oleh   : Tim Developer CGV\n";
    cout << "Bahasa        : C++\n";
    cout << "\nFitur yang Tersedia:\n";
    cout << "  - Pembelian tiket bioskop\n";
    cout << "  - Pemilihan kursi interaktif\n";
    cout << "  - Pemesanan snack dan minuman\n";
    cout << "  - Sistem member dan poin reward\n";
    cout << "  - Voucher dan promo diskon\n";
    cout << "  - Filter dan pencarian film\n";
    cout << "  - Jadwal tayang harian\n";
    cout << "  - Sistem antrian digital\n";
    cout << "  - Ulasan dan rating film\n";
    cout << "  - Riwayat transaksi\n";
    cout << "  - Laporan statistik penjualan\n";
    cout << "\nKontak Support:\n";
    cout << "  Email   : support@cgvcinemas.com\n";
    cout << "  WhatsApp: +62 812-3456-7890\n";
    cout << "  Jam     : 09.00 - 21.00 WIB\n";
    cout << "====================================================\n";
}

/* =========================
   MAIN
========================= */
int main() {

    int pilih;

    do {
        tampilMenuUtama();
        cin >> pilih;

        switch(pilih) {
            case 1:
                prosesPembelianTiket();
                break;
            case 2:
                menuInfoFilm();
                break;
            case 3:
                menuMember();
                break;
            case 4:
                menuAntrian();
                break;
            case 5:
                menuLaporan();
                break;
            case 6:
                tampilInfoBioskop();
                break;
            case 7:
                tampilPeraturanBioskop();
                break;
            case 8:
                menuBantuan();
                break;
            case 9:
                tampilTentangAplikasi();
                break;
            case 0:
                cout << "\n[INFO] Terima kasih telah menggunakan sistem CGV!\n";
                cout << "[INFO] Sampai jumpa!\n\n";
                break;
            default:
                cout << "[!] Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while(pilih != 0);

    return 0;
}
