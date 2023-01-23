#Generate Transition Matrix
import numpy as np
import random

class Transition:
    def __init__(self, m, n):
        
        self.transition_matrix = []
        self.m=m
        self.n=n
        """
        self.dist = ["uniform","pareto","expovariate"]

        for i in range(self.nodes):
            self.transition_matrix.append(self.gen_state_prob(self.k,self.dist[0])) #SELECT DIST
            
            if sum(self.transition_matrix[i]) != 1:
                add = 1- sum(self.transition_matrix[i])
                self.transition_matrix[i][0] += add
                self.transition_matrix[i][0] = round(self.transition_matrix[i][0],2)
            
            
        for i in range(self.k):
            for j in range(self.k):
                self.transition_matrix[i][j] = round(self.transition_matrix[i][j], 2)
        
        if len(self.transition_matrix) != n: print("Error generating transition matrix")
        """
    def gen_state_prob(self,K=3, distribution="uniform"):
        """
        k=K
        a, m = 3., 2.  #Pareto
        result = []
        r=0

        if distribution == "uniform":
            #result = [[np.random.default_rng().uniform(0, 0.1 / k) for i in range(k)] for j in range(k)]
            result = np.identity(k) + np.random.uniform(low=0., high=1., size=(k, k))
            result /= result.sum(axis=1, keepdims=1)
        elif distribution == "pareto":
            result = [[(np.random.default_rng().pareto(a, 3) + 1) * m for i in range(k)] for j in range(k)]
            #print("\n\n", distribution, "-before->", type(result), result)
            temp= [result[0][i] for i in range(k)]
            result=temp
            #print("\n\n", distribution, "-after->", type(result), result)
            #return
        elif distribution == "expovariate":
            result = [[random.expovariate(alpha/k) for i in range(k)] for j in range(k)]

        #print("\n\n", distribution, "-->", result)
        #return

        for j, r in enumerate(result):
            r[j] += 1 - sum(r)
            
        
        #for x in transition_matrix:
        #    print(x, sum(x))
        self.transition_matrix = result
        self.transition_matrix = [list(x) for x in self.transition_matrix]
        """

        # Create an array of probabilities that sum to 1
        #probabilities = [0.2, 0.3, 0.5]

        # Create a 3x3 transition matrix
        self.transition_matrix = np.zeros((self.m, self.n))

        # Fill in the transition matrix with random values according to the probabilities
        for i in range(self.m):
            self.transition_matrix[i] = np.random.dirichlet(np.ones(self.n),size=1)
            '''
            for j in range(self.n):
                prob = np.random.choice(probabilities)
                while(True):
                    if prob not in self.transition_matrix[i]:
                        self.transition_matrix[i, j] = prob
                        break
                    else:
                        prob = np.random.choice(probabilities)
            '''

    def get_transition_matrix(self):
        return self.transition_matrix