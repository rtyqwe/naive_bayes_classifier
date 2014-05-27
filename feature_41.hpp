/*
 * feature.hpp
 *
 *  Created on: May 3, 2011
 *      Author: Ethan L. Schreiber
 *      Adapted from java code written by Andrew McGregor
 */

#ifndef FEATURE_HPP_
#define FEATURE_HPP_

#include <string>
#include <cstring>
#include <iostream>
using std::string;

#ifndef FEATURE_ENUM_
#define FEATURE_ENUM_
enum FeatureType {ALPHABET, VOWEL};
#endif /* FEATURE_ENUM_ */
/**
 * feature.hpp
 *
 * Stores counts and computes probabilities for one boolean feature.
 */
class Feature {

  /* counts[][] is a 2x2 matrix that stores for each of the
   * 2 classes (0 and 1), the number of training examples we've
   * seen that don't have the feature (0) or have it (1).
   *
   * So counts[0][0] would be the number of training examples that fall
   * into class 0, that don't have the feature.
   *
   * totalPerClass[] stores the number of training examples we've seen
   * per class.  So totalPerClass[i] should always equal
   * counts[i][0] + counts[i][1].
   */

protected:
  int m_counts[2][2];
  int m_totalPerClass[2];
  string m_toMatch;
  FeatureType m_type;

public :
  Feature(string toMatch, FeatureType type) : m_toMatch(toMatch), m_type(type){

    // Initialize the counters to 0
    m_counts[0][0] = 0;
    m_counts[0][1] = 0;
    m_counts[1][0] = 0;
    m_counts[1][1] = 0;

    m_totalPerClass[0] = 0;
    m_totalPerClass[1] = 0;
  }

  int isFeaturePresent(string s) {
    if (m_type == ALPHABET) {
      string upperS;
      for(size_t i = 0; i < s.size(); i++){
        if(toupper(s.at(i)) == m_toMatch[0])
          return 1;
      }  //make the case of string same as feature
    }

    //check if there are more than 3 vowels in the string
    else if (m_type == VOWEL) {

      int vowelCount = 0;
      for(size_t i = 0; i < s.size(); i++){
        if(toupper(s.at(i)) == 'A'||
          toupper(s.at(i)) == 'E'||
          toupper(s.at(i)) == 'I'||
          toupper(s.at(i)) == 'O'||
          toupper(s.at(i)) == 'U'
          )
          vowelCount++;
      }
      //std::cerr << "Vowel count: " << vowelCount<<std::endl;
      double percentageV = ((double) vowelCount/(double)s.size());
      if(percentageV >= 0.40){
        return 1;
      }
    }
    
    return 0;

    /* 
     *
     * Determine whether this feature occurs in the string.
     * Return 1 if the feature is present; 0 otherwise.
     */
  }

  void addTrainingExample(int featurePresence, int classNumber) {
    m_counts[classNumber][featurePresence]++;
    m_totalPerClass[classNumber]++;
    /* 
     *
     * Given the absence/presence of this feature for the given class,
     * update the counts used to compute the probabilities.
     *
     * classNumber = the number of the class for this example (0 or 1)
     * featurePresence = 0 or 1 stating the presence or absence of this feature
     */
  }

  double getProbOfFeatureGivenClass(int featurePresence, int classNumber) {
    /*
     *
     * What is the probability of this feature being absent/present for this class?
     * Use your counts, but make sure to smooth it by adding 1 to avoid probabilities of
     * absolute zero or one.
     */
    //.. you need to smooth it so there's never a 0 or 1 probability
     int featureCount = m_counts[classNumber][featurePresence];
     int total = m_totalPerClass[classNumber];
     featureCount++;
   // total+=2;
     double returnVal = ((double) featureCount)/((double) total);
     return returnVal;

  }
};

#endif /* FEATURE_HPP_ */
