Tema 1
Nume:Marinescu Victor-Florentin
Grupa: 324AB
Sistem de operare: Windows 10
IDE: Visual Studio Code

Programul facut contine 3  clase (Produs, Comanda si Client).
Clasa Produs contine constructorul Default, 3 setteri, 4 getteri si 3 operatori ("=","<<",">>"). Clasa Comanda este similar, cu setteri si getteri pentru valorile necesare si operatorii de atribuire si citire/afisare, dar pe langa astea am facut o functie friend ce are rol de a scadea stocul curent din comenzile primite. Clienti contine doar setterii, getterii si operatorii (=,<<,>>).
In main, programul primeste 2 fisiere ca argumente de input si se aleg 2 fisiere de output. Citesc fisierul de produse si le introduc in clasa de Produs, verific daca sunt comenzi si cu fiecare comanda citita, scad stocul si continui cu urmatoarea comanda. Dupa terminarea comenzilor, afisez, in fisierele de output, stocul ramas, respectiv comenzile.