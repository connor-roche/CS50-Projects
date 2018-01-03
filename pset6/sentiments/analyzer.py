import nltk

class Analyzer():
    #Implements sentiment analysis

    def __init__(self, positives, negatives):
        self.positives = set()
        self.negatives = set()
        
        #load positive words
        file_positive = open("positive-words.txt", "r")
        for line in file_positive:
            if line.startswith(";") == False:
                self.positives.add(line.rstrip("\n"))
        file_positive.close()
        
        #loads negative words   
        file_negative = open("negative-words.txt", "r")
        for line in file_negative:
            if line.startswith(";") == False:
                self.negatives.add(line.rstrip("\n"))
        file_negative.close()
        

    def analyze(self, text):
        #Analyze text for sentiment, returning its score.
        
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        
        score = 0
        
        #assign score to word
        for word in tokens:
            if word.lower() in self.positives:
                score += 1
            elif word.lower() in self.negatives:
                score -= 1
        
        return score