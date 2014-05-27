#!/bin/sh

#test 2a
./textClassifier dat/cities/usCities100.txt dat/cities/russiaCities100.txt dat/cities/usCitiesNext50.txt dat/cities/russiaCitiesNext50.txt

#test 2b
./textClassifier dat/cities/russiaCities100.txt dat/cities/otherCities100.txt dat/cities/russiaCitiesNext50.txt dat/cities/otherCitiesNext50.txt

#test 2c
./textClassifier dat/cities/usCities100.txt dat/cities/otherCities100.txt dat/cities/usCitiesNext50.txt dat/cities/otherCitiesNext50.txt

#test 3 Hasselhoff (fresh test data)
./textClassifier dat/tweets/hasselhoff_de_train.txt dat/tweets/hasselhoff_en_train.txt dat/tweets/hasselhoff_de_test.txt dat/tweets/hasselhoff_en_test.txt

#test 3 Hasselhoff (same training data)
./textClassifier dat/tweets/hasselhoff_de_train.txt dat/tweets/hasselhoff_en_train.txt dat/tweets/hasselhoff_de_train.txt dat/tweets/hasselhoff_en_train.txt

#test 3 democrat vs. republican
./textClassifier dat/tweets/democrat_en_train.txt dat/tweets/republican_en_train.txt dat/tweets/democrat_en_test.txt dat/tweets/republican_en_test.txt

