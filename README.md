# Papildoma uzduotis
# Asociatyvūs konteineriai

Programa skirta suskaičiuoti:
- kiek kartų pasikartoja skirtingi žodžiai
- atspausdinti cross-reference lentelę, kurioje matytusi, kuriose teksto eilutėse yra atitinkamas žodis
- išrinkti iš teksto URL adresus ir juos atspausdinti atskirame faile.

## Veikimo principas

Programos veikimo pabaigoje yra sukuriami 3 failai, kuriuose yra visa informacija apie text.txt failą.

## Programos diegimas ir paleidimas

- Atsisiųskite programos versiją iš (https://github.com/) aplanko ir ją išsiarchyvuokite,
- Komandinėje eilutėje įvykdykite sekančius veiksmus:

cd nuoroda_į_programos_aplanką
g++ -o main  main.cpp -std=c++17 && .\main.exe
