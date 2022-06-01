# project_08_34288


## Zawartość
* [Konfiguracja](#konfiguracja)
* [Uruchomienie](#uruchomienie)
* [Instukcja](#instrukcja)

## Konfiguracja
1. WAŻNE w plikach csv nie wolno w komórkach używać przecinków, zawsze trzeba używać 3 wartości cen S/M/L
    - dough.csv: podajemy listę rodzajów ciasta na pizzę
    - drink.csv: podajemy listę napojów
    - ingredient.csv: podajemy listę składników na dowolną pizzę
    - set.csv: podajemy listę zestawów pizzy 
    - specialOfferPrice.csv: podajemy promocję w pierwszej linii kwota od której obowiązuje, wartość promocji w postaci ułamka dziesiętnego(np 50% to 0.5)
2. W pliku path.txt podajemy ścieżkę gdzie ma być zapisywany paragon

## Uruchomienie
1. Kopiujemy repozytorium komendą:
    ```
    git clone https://github.com/MateuszH96/PizzaTime.git
    ```
2. W głównym folderze przechodzimy do folderu build
    ```
    cd build
    ``` 
3. Zmieniamy prawa dostępu do pliku ``Run.sh`` na np:
    ```
    chmod 777 Run.sh
    ``` 
4. Uruchamiamy aplikację wraz z kompilacją komendą
    ```
    ./Run.sh
    ```
## Instrukcja
Aplikacja jest prosta w obsłudze

Posługujemy się klawiaturą i wpisujemy wyświatlone informację np:

numer zamówienia(1,2,3,...)

wielkość zamówienia(S,M,L)

Potwierdzenie(Y,N)