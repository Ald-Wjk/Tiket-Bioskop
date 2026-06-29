#include <iostream> //ya
using namespace std;

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


int main() {
	
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
	
	t.harga=f.hargaTiket;
	cout<<"Harga : Rp "<<t.harga<<endl;
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

	cout<<"\n===== PEMBAYARAN ====="<<endl;
	cout<<"1. Cash"<<endl;
	cout<<"2. Debit"<<endl;
	cout<<"3. QRIS"<<endl;
	
	cout<<"Pilih : ";
	cin>>metode;
	
	switch(metode)
	{
	case 1:
	    p.metode="Cash";
	    break;
	
	case 2:
	    p.metode="Debit";
	    break;
	
	case 3:
	    p.metode="QRIS";
	    break;
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

    return 0;
}
