
# 💻 Wizualna Transformacja Untermów: Pozioma $\leftrightarrow$ Pionowa (MASI Projekt)

Unitermy to podstawowe jednostki opisu algorytmów w ujęciu algebraicznym. Ten projekt to aplikacja desktopowa stworzona w **C++ z Qt 6**, która wizualnie demonstruje i realizuje transformację algebraicznej struktury **unitermu z poziomej operacji eliminowania na postać pionową**.

Aplikacja ma na celu graficzne odzwierciedlenie operacji zamiany, zgodnie z rozszerzoną algebrą algorytmów, oraz umożliwia archiwizację przeprowadzonych transformacji w lokalnej bazie danych.

-----

## ✨ Kluczowe Funkcjonalności

  * **Wizualizacja Unitermów:** Graficzne przedstawienie unitermów w dwóch formach:
      * **Poziomej:** $A ; B ; u - ?$.
      * **Pionowej:** $1 ; 2 ; w - ?$.
  * **Interaktywna Transformacja:** Możliwość zamiany unitermu poziomego na pionowy poprzez podstawienie pionowej formy w miejsce jednego z operandów:
      * **"Zamień za A"**.
      * **"Zamień za B"**.
  * **Lokalna Baza Danych (SQLite):** Trwałe zapisywanie danych transformacji do pliku `moja_baza.db`.
  * **Archiwizacja Danych:** Formularz do zapisywania nazwy i opisu operacji wraz z wartościami unitermów ($val1$, $val2$, $valW$, $valA$, $valB$, $valU$).
  * **Przegląd Historii:** Dedykowane okno do wglądu w zapisane rekordy w formie tabelarycznej.

-----

## 🛠️ Technologie

Projekt jest samodzielną aplikacją desktopową (Standalone Application).

| Kategoria | Technologia | Uwagi |
| :--- | :--- | :--- |
| **Język Programowania** | C++ | Zapewnienie wydajności i pełnej kontroli nad logiką. |
| **Framework GUI** | **Qt 6 (QtWidgets, QtSql, QtGui)** | Wieloplatformowy framework do tworzenia graficznego interfejsu. |
| **Baza Danych** | **SQLite (lokalna)** | Wykorzystuje biblioteki QtSql do przechowywania danych w pliku `moja_baza.db`. |
| **Rysowanie** | `QPainter` | Klasa odpowiedzialna za niestandardowe rysowanie komponentów (linii, tekstu) w metodzie `paintEvent`. |

-----

## 🏗️ Struktura Projektu

Aplikacja oparta jest na architekturze warstwowej i wzorcach obiektowych (OOP), z jasną separacją logiki od warstwy prezentacji (UI) i dostępu do danych (DAL).

| Moduł / Klasa | Opis Odpowiedzialności |
| :--- | :--- |
| `main.cpp` / `MainWindow` | Główny kontroler. Tworzy interfejs, obsługuje interakcje użytkownika i koordynuje przepływ danych. |
| `VerticalWidget` / `HorizontalWidget` | Komponenty View. Samodzielne rysowanie unitermów w układzie pionowym/poziomym za pomocą `QPainter`. |
| `ASwapWidget` / `BSwapWidget` | Wizualizacja wyniku transformacji (zagnieżdżenie pionowego unitermu w miejscu A lub B). |
| `database.cpp` / `database.h` | Warstwa Dostępu do Danych (DAL). Statyczne metody do inicjalizacji bazy i operacji $INSERT / SELECT$. |
| `save.cpp` / `save.h` | Okno dialogowe do wprowadzania metadanych ($Nazwa, Opis$) przed zapisem do bazy. |
| `globals.cpp` / `globals.h` | Przechowuje zmienne globalne ($val1...valU$) udostępniane między komponentami. |

-----

## 🚀 Kompilacja i Uruchomienie

Projekt wymaga środowiska **Qt 6** (z modułami $QtWidgets$, $QtSql$, $QtGui$).

1.  **Pobierz kod:**


2.  **Kompilacja (Qt Creator lub wiersz poleceń):**

      * Użyj **Qt Creator** do otwarcia pliku `.pro` i zbudowania projektu.

3.  **Uruchomienie:**

      * Uruchom skompilowany plik wykonywalny.
      * Przy pierwszym uruchomieniu zostanie automatycznie utworzony plik bazy danych **`moja_baza.db`** w katalogu aplikacji.

-----

## 🖼️ Zrzuty Ekranu

| Funkcjonalność | Opis | Wizualizacja |
| :--- | :--- | :--- |
| **Uniterm Poziomy** | Reprezentacja $A ; B ; u - ?$ po wprowadzeniu danych. |  |
| **Uniterm Poziomy i Pionowy** | Jednoczesna prezentacja obu struktur eliminowania unitermów. |  |
| **Okno Wyboru Zamiany** | Interaktywny wybór wariantu transformacji: "Zamień za A" lub "Zamień za B". |  |
| **Wynik Zamiany za B** | Graficzny rezultat transformacji: pionowy uniterm osadzony w miejscu operandu B. |  |
| **Podgląd Zapisów** | Widok tabelaryczny wszystkich archiwizowanych rekordów z bazy SQLite. |  |

-----

## 👤 Autor

  * **Mateusz Misiak** (Numer indeksu: 91297)
  * **Uczelnia:** Politechnika Świętokrzyska, Wydział Elektrotechniki, Automatyki i Informatyki
  * **Przedmiot:** Modelowanie i analiza systemów informatycznych – Projekt

-----
