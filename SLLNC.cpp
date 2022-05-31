// 1121031058
// Muhammad Nabiel Bawazier
// SLLNC.cpp 
// program singgle linked list non circular dengan head dan tail
// Dengan tambahan Function mencari data tertentu
// dan Menghapus data Tertentu
#include <cstddef>
#include <iostream> 
  
 using namespace std; 
  
 struct TNode { 
     int data;       // field data 
     TNode *next;    // field pointer 
 }; 
  
 TNode *head; // deklarasi variabel pointer head untuk menunjukkan kepala node 
TNode *tail;
TNode *in;
  
 void init() { 
     head = NULL; // inisialisasi linked list kosong (tanpa node sama sekali) 
     //tail = NULL; 
 } 
  
 int isEmpty() { 
     if (head == NULL) { 
         return 1;   // kembalikan 1 kalau linked list masih kosong 
     } else { 
         return 0;   // kembalikan 0 kalau linked list sudah ada isinya 
     } 
 } 
  
 void insertDepan(int dataBaru) { 
     TNode *nodeBaru;        // step 1. buatlah node baru 
     nodeBaru = new TNode; 
  
     nodeBaru->data = dataBaru;  // step 2. input data yang diinginkan di node yang baru 
     nodeBaru->next = NULL;      // node belum disambungkan ke linked list 
  
     if (isEmpty() == 1) {       // step 3. cek apakah linked list masih kosong atau tidak 
         head = nodeBaru;        // kondisi 1. linked list masih kosong sehingga pointer head kita pindahkan ke node yang baru 
         head->next = NULL; 
     } else { 
         nodeBaru->next = head;  // kondisi 2. linked list sudah terbentuk sehingga node yang baru menjadi kepala dari linked list 
         head = nodeBaru; 
     } 
  
     cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl; 
 } 
  
 void insertBelakang(int dataBaru) { 
     TNode *nodeBaru, *nodeBantu;    // step 1. buatlah node baru dan node bantu 
     nodeBaru = new TNode; 
  
     nodeBaru->data = dataBaru;  // step 2. input data yang diinginkan di node yang baru 
     nodeBaru->next = NULL;      // node belum disambungkan ke linked list 
  
     if (isEmpty() == 1) {   // step 3. cek apakah linked list masih kosong atau tidak 
         head = nodeBaru;    // kondisi 1. linked list masih kosong sehingga pointer head kita pindahkan ke node yang baru 
         head->next = NULL; 
     } else { 
         nodeBantu = head;   // kondisi 2. linked list sudah terbentuk, tempatkan nodeBantu di head sebagai awal tracing 
  
         while (nodeBantu->next != NULL) {   // lakukan looping dengan menggunakan variabel bantu untuk mencari ekor dari linked list 
             nodeBantu = nodeBantu->next;    // ekor dari linked list ditunjukkan dengan pointer next = NULL 
         } 
  
         nodeBantu->next = nodeBaru; // keluar looping, ekor linked list disambungkan ke node yang baru 
     } 
  
     cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl; 
 } 
  
 void hapusDepan() { 
     TNode *hapus; 
     int d; 
  
     if (isEmpty() == 0) { 
         if(head->next != NULL){ 
             hapus = head; 
             d = hapus->data; 
             head = head->next; 
             delete hapus; 
         } else { 
             d = head->data; 
             head = NULL; 
         } 
     cout << "Data " << d << " terhapus" << endl; 
     } else { 
         cout<<"Linked List masih kosong\n"; 
     } 
 } 
  
 void hapusBelakang() { 
     TNode *hapus,*nodeBantu; 
     int d; 
  
     if (isEmpty()==0) { 
         if(head->next != NULL){ 
             nodeBantu = head; 
             while(nodeBantu->next->next!=NULL){ 
                 nodeBantu = nodeBantu->next; 
             } 
             hapus = nodeBantu->next; 
             d = hapus->data; 
                       nodeBantu->next = NULL; 
             delete hapus; 
         } else { 
             d = head->data; 
             head = NULL; 
         }
       cout << "Data " << d << " terhapus" << endl; 
           } else { 
         cout<<"Linked List masih kosong\n"; 
     } 
 } 
  
 void hapusSemua() { 
     TNode *nodeBantu, *hapus; 
     nodeBantu = head; 
  
     while(nodeBantu != NULL) { 
         hapus = nodeBantu; 
         nodeBantu = nodeBantu->next; 
         delete hapus; 
     } 
     head = NULL; 
     cout << "Linked List kosong\n"; 
 } 
  
 void tampilData() { 
     TNode *nodeBantu; // step 1. buatlah node bantu 
  
     nodeBantu = head; // tempatkan node bantu di head sebagai awal tracing 
  
     if (isEmpty() == 0) {   // kondisi 1. linked list tidak kosong 
         while (nodeBantu != NULL) {             // lakukan looping dengan menggunakan variabel bantu sampai ketemu ekor dari linked list 
             cout << nodeBantu->data << " | ";    // tampilkan data dari setiap node yang dilalui 
             nodeBantu = nodeBantu->next;        // pindahkan node bantu ke node selanjutnya 
         } 
     } else { 
         cout << "List masih kosong" << endl;    // kondisi 2. linked list masih kosong 
     } 
 } 

void cariData( int cari){
  TNode *nodeBantu;
  // bool ketemu = false;
  nodeBantu = head;
    if(isEmpty() != 1){
      while (nodeBantu != NULL){
        if (nodeBantu ->data == cari){
          // ketemu = true;
          cout << "Ketemu Data -> " << nodeBantu->data ;
          return;
        } 
          nodeBantu = nodeBantu -> next;
      }
            cout << "Data tidak ditemukan\n";
    }else{cout << "Data tidak ditemukan List Kosong\n"; }
  
}

void hapusData(int input){
  TNode* nodeBantu = head; 
    TNode* hapus = NULL; 
  if (isEmpty() != 1 ){
     if (nodeBantu != NULL && nodeBantu->data == input){ 
         head = nodeBantu->next; // mengubah node head 
         delete nodeBantu;       // menghapus node yang diinginkan
         return; 
     } 
       else{ 
         while (nodeBantu != NULL && nodeBantu->data != input){ 
           hapus = nodeBantu; 
           nodeBantu = nodeBantu->next; 
         }
         if (nodeBantu == NULL){
           cout << "Data tidak ditemukan\n";
         } hapus->next = nodeBantu->next;     
       }
  cout << "Data " << input << " telah dihapus\n" ;
  tampilData();
    }cout << "Data tidak ditemukan List Kosong\n";
}


  
 int main() { 
     int pil, dataBaru; 
  
     do { 
         cout<<" \n"<<endl; 
         cout<<" =============================="<<endl; 
         cout<<" =   PROGRAM LINKED LIST      ="<<endl; 
         cout<<" =============================="<<endl; 
         cout<<" = 1. Insert Depan            ="<<endl; 
         cout<<" = 2. Insert Belakang         ="<<endl; 
         cout<<" = 3. Hapus Depan             ="<<endl; 
         cout<<" = 4. Hapus Belakang          ="<<endl; 
         cout<<" = 5. Tampil Data             ="<<endl; 
         cout<<" = 6. Hapus semua Data        ="<<endl; 
         cout<<" = 7. Mencari Data Tertentu   ="<<endl; 
         cout<<" = 8. Menghapus Data Tertentu ="<<endl; 
         cout<<" = 9. Exit                    ="<<endl; 
         cout<<" =============================="<<endl; 
         cout<<" Masukan Pilihan : "; 
         cin>>pil; 
  
         if (pil == 1) { 
             cout<<"Masukan Data = "; 
             cin>>dataBaru; 
             insertDepan(dataBaru); 
         } else if (pil == 2) { 
             cout<<"Masukan Data = "; 
             cin>>dataBaru; 
             insertBelakang(dataBaru); 
         } else if (pil == 3) { 
             hapusDepan(); 
         } else if (pil == 4) { 
             hapusBelakang(); 
         } else if (pil == 5) { 
             tampilData(); 
         } else if (pil == 6) { 
             hapusSemua(); 
         } else if (pil == 7){
           cout << "Masukkan data yang ingin dicari = ";
           cin >>dataBaru;
           cariData(dataBaru);
         } else if (pil == 8){
           cout << "Masukkan data yang ingin dihapus = ";
           cin >>dataBaru;
           hapusData(dataBaru);
         } 
         else if (pil != 9) { 
             cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!"; 
         } 
     } while (pil != 9); 
  
     return 0; 
 }
