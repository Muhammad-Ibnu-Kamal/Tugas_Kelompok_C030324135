#include <iostream>
  #include <vector>
  #include <string>
  using namespace std;

  struct Course {
      string package_name;
      string type;
      int meetings;
      int session_duration;
      double price_per_meeting;
      int registered_students;
      string payment_status;
  };

  vector<Course> courses;

  void addCourse() {
      Course newCourse;
      cout << "\nMasukkan nama paket kursus: ";
      cin.ignore();
      getline(cin, newCourse.package_name);
      cout << "Pilih tipe paket (1: Privat, 2: Kelas): ";
      int typeChoice;
      cin >> typeChoice;
      newCourse.type = (typeChoice == 1) ? "Privat" : "Kelas";
      cout << "Masukkan jumlah pertemuan: ";
      cin >> newCourse.meetings;
      cout << "Masukkan durasi per sesi (menit): ";
      cin >> newCourse.session_duration;
      cout << "Masukkan harga per pertemuan: ";
      cin >> newCourse.price_per_meeting;
      newCourse.registered_students = 0;
      newCourse.payment_status = "Belum Dibayar";
      courses.push_back(newCourse);
      cout << "Paket kursus berhasil ditambahkan!\n";
  }

  int main() {
      addCourse();
      return 0;
  }