#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath> // sqrt için gerekli

using namespace std;

// 1. ADIM: Veri Yapısı (En üstte kalmalı)
struct Patient {
    vector<double> features;
    int label;
};

// 2. ADIM: Fonksiyonları main'in ÜSTÜNE taşıyoruz ki main onları tanısın
double calculateDistance(const Patient& p1, const Patient& p2) {
    double sum = 0.0;
    for (size_t i = 0; i < p1.features.size(); ++i) {
        double diff = p1.features[i] - p2.features[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int predictKNN(const vector<Patient>& dataset, const Patient& query, int k) {
    vector<pair<double, int>> distances;
    for (const auto& p : dataset) {
        double dist = calculateDistance(p, query);
        distances.push_back({ dist, p.label });
    }
    sort(distances.begin(), distances.end());

    int vote_1 = 0;
    int vote_0 = 0;
    for (int i = 0; i < k; ++i) {
        if (distances[i].second == 1) vote_1++;
        else vote_0++;
    }
    return (vote_1 > vote_0) ? 1 : 0;
}

// 3. ADIM: Ana Program
int main() {
    ifstream file("data.csv");
    string line;
    vector<Patient> dataset;

    if (!file.is_open()) {
        cout << "Hata: data.csv dosyasi bulunamadi!" << endl;
        return 1;
    }

    getline(file, line); // Başlık atla

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        Patient p;
        int col = 0;
        while (getline(ss, value, ',')) {
            if (col == 1) p.label = (value == "M") ? 1 : 0;
            else if (col > 1) p.features.push_back(stod(value));
            col++;
        }
        dataset.push_back(p);
    }
    file.close();

    cout << "Basariyla " << dataset.size() << " hasta kaydi yuklendi." << endl;

    // --- PERFORMANS TESTİ: Tüm Veri Setini Test Etme ---
    if (!dataset.empty()) {
        int dogruTahminSayisi = 0;
        int k = 5; // Komşu sayısı

        cout << "Analiz baslatiliyor, lutfen bekleyin..." << endl;

        for (const auto& testHasta : dataset) {
            int tahmin = predictKNN(dataset, testHasta, k);

            if (tahmin == testHasta.label) {
                dogruTahminSayisi++;
            }
        }

        // Başarı oranını hesapla
        double basariOrani = (double)dogruTahminSayisi / dataset.size() * 100;

        cout << "------------------------------------" << endl;
        cout << "TOPLAM HASTA SAYISI: " << dataset.size() << endl;
        cout << "DOGRU TAHMIN       : " << dogruTahminSayisi << endl;
        cout << "BASARI YUZDESI     : %" << basariOrani << endl;
        cout << "------------------------------------" << endl;
    }
}