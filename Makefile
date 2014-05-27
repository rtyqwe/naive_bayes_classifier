CC=g++

FLAGS = -Wall

all: textClassifier textClassifier_41

textClassifier : feature.hpp naive_bayes_classifier.hpp string_utilities.hpp text_classifier.cpp
	$(CC) $(FLAGS) text_classifier.cpp -o $@

textClassifier_41 : feature_41.hpp naive_bayes_classifier_41.hpp string_utilities.hpp text_classifier_41.cpp
	$(CC) $(FLAGS) text_classifier_41.cpp -o $@

clean: 
	rm -f textClassifier
	rm -f textClassifier_41
	
