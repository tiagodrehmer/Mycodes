#!/bin/bash

# >> redireciona a saida para um arquivo
#a = REPETICOES
#b = tipo de TREE

TREE=( "AVL" "BST" "SPLAY")

REPETICOES=100
TEMPO_1=0
TEMPO_2=0
TEMPO_3=0
TEMPO_4=0
SOMADOR_1=0
SOMADOR_2=0
SOMADOR_3=0
SOMADOR_4=0

mkdir testes #cria pasta onde vai colocar os files com os dados

######################################################################
#PUT
for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  make put
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main_put -p ../files/put_200_1000.csv -S ../files/Sp.txt`
    TEMPO_2=`./main_put -p ../files/put_200_2500.csv -S ../files/Sp.txt`
    TEMPO_3=`./main_put -p ../files/put_200_5000.csv -S ../files/Sp.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media

  make clean_put

  cd ../testes

  printf "200x1000 - $SOMADOR_1 ms \n" > ${TREE[$b]}_PUT.dat
  printf "200x2500 - $SOMADOR_2 ms \n" >> ${TREE[$b]}_PUT.dat
  printf "200x5000 - $SOMADOR_3 ms \n" >> ${TREE[$b]}_PUT.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done

######################################################################
#GET
for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  make
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -g ../files/teste_50_15000.csv -S ../files/Spg.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -g ../files/teste_50_25000.csv -S ../files/Spg.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -g ../files/teste_50_50000.csv -S ../files/Spg.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -g ../files/teste_50_100000.csv -S ../files/Spg.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media

  cd ../testes
  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_GET.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_GET.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_GET.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_GET.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done

######################################################################
#DELETE

for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -d ../files/teste_50_15000.csv -S ../files/Spd.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -d ../files/teste_50_25000.csv -S ../files/Spd.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -d ../files/teste_50_50000.csv -S ../files/Spd.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -d ../files/teste_50_100000.csv -S ../files/Spd.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media

  cd ../testes

  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_DELETE.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_DELETE.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_DELETE.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_DELETE.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done

######################################################################
#CONTAINS
for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -c ../files/teste_50_15000.csv -S ../files/Spc.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -c ../files/teste_50_25000.csv -S ../files/Spc.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -c ../files/teste_50_50000.csv -S ../files/Spc.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -c ../files/teste_50_100000.csv -S ../files/Spc.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media

  cd ../testes

  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_CONTAINS.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_CONTAINS.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_CONTAINS.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_CONTAINS.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done
######################################################################
#RANK

for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -R ../files/teste_50_15000.csv -S ../files/SpR.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -R ../files/teste_50_25000.csv -S ../files/SpR.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -R ../files/teste_50_50000.csv -S ../files/SpR.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -R ../files/teste_50_100000.csv -S ../files/SpR.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media

  cd ../testes

  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_RANK.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_RANK.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_RANK.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_RANK.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done
######################################################################
#CEILING

for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -C ../files/teste_50_15000.csv -S ../files/SpCeil.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -C ../files/teste_50_25000.csv -S ../files/SpCeil.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -C ../files/teste_50_50000.csv -S ../files/SpCeil.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -C ../files/teste_50_100000.csv -S ../files/SpCeil.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`

  done
  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media

  cd ../testes
  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_CEIL.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_CEIL.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_CEIL.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_CEIL.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done

######################################################################
#FLOOR

for b in `echo ${!TREE[*]}`;do
  cd ${TREE[$b]}_Shopping
  for ((a=1; a <= $REPETICOES ; a++))
  do
    TEMPO_1=`./main -p ../files/put_200_5000.csv -F ../files/teste_50_15000.csv -S ../files/SpF.txt`
    TEMPO_2=`./main -p ../files/put_200_5000.csv -F ../files/teste_50_25000.csv -S ../files/SpF.txt`
    TEMPO_3=`./main -p ../files/put_200_5000.csv -F ../files/teste_50_50000.csv -S ../files/SpF.txt`
    TEMPO_4=`./main -p ../files/put_200_5000.csv -F ../files/teste_50_100000.csv -S ../files/SpF.txt`

    SOMADOR_1=`echo "scale=5;$SOMADOR_1+$TEMPO_1" | bc`
    SOMADOR_2=`echo "scale=5;$SOMADOR_2+$TEMPO_2" | bc`
    SOMADOR_3=`echo "scale=5;$SOMADOR_3+$TEMPO_3" | bc`
    SOMADOR_4=`echo "scale=5;$SOMADOR_4+$TEMPO_4" | bc`
  done

  SOMADOR_1=`echo "scale=5;$SOMADOR_1/$REPETICOES" | bc` #fazendo a media
  SOMADOR_2=`echo "scale=5;$SOMADOR_2/$REPETICOES" | bc` #fazendo a media
  SOMADOR_3=`echo "scale=5;$SOMADOR_3/$REPETICOES" | bc` #fazendo a media
  SOMADOR_4=`echo "scale=5;$SOMADOR_4/$REPETICOES" | bc` #fazendo a media
  make clean #o ultimo limpa tudo

  cd ../testes

  printf "50x15000 - $SOMADOR_1 ms\n" > ${TREE[$b]}_FLOOR.dat
  printf "50x25000 - $SOMADOR_2 ms\n" >> ${TREE[$b]}_FLOOR.dat
  printf "50x50000 - $SOMADOR_3 ms\n" >> ${TREE[$b]}_FLOOR.dat
  printf "50x100000 - $SOMADOR_4 ms\n" >> ${TREE[$b]}_FLOOR.dat
  #reset das variaveis
  SOMADOR_1=0
  SOMADOR_2=0
  SOMADOR_3=0
  SOMADOR_4=0
  cd ..
done
