
from MarkovProcess import MarkovChain
from Transition import Transition

class Simulate:
    
    def __init__(self,steps):
        self.lMap = []                     #holds all timeSteps/snapshots from the map
        self.lCars = []
        self.addCars = False                #True: adds cars at every time step
        self.addActCars = False             #True: only adds actual cars data. False: adds predictive car data
        self.LearningFeatures = []
        self.LearningLabels = []
        self.TestingFeatures = []
        self.TestingLabels = []
        self.tSteps = steps
    
    def updateTransitionMatrix(self,tm_0, tm_1, cars_0, cars_1):
        #how to change transition matrix when new cars are added
        return tm_1

    #if true, adds new cars to intersection
    #if false, carries over only the cars coming in from previous intersections
    def addNewCars(self,cars):
        if self.addCars: return cars
        else: return 0

    def addActualCars(self,cars):
        if self.addActCars: return 0
        else: return cars
        
    #updates lMap with newly added cars after every time period
    def updateMap(self,lMap, cars, step):
        
        flatFeatures = []
        #dVertices[i] = {0, [step,[[transition_matrix]], state, 0]}
        T = Transition(3,3)

        if len(self.lMap) > 0:
            mostRecentTimeStep = self.lMap[(len(self.lMap)-1)]
            #print("mostRecentTimeStep",mostRecentTimeStep)
            nextTimeStep = {}
            prevState = mostRecentTimeStep[0][2]  #copy previous state from last time step
            #print(prevState)
            #print("mostRecentTimeStep[0][2]",mostRecentTimeStep[0][2])
            #print("mostRecentTimeStep[0][1][1][1]",mostRecentTimeStep[0][1][1][1])

            for i in range(len(self.tSteps)):
                # Generate Transition Matrix for intersection i and assign to intersection
                T.gen_state_prob(3,"uniform")
                transition_matrix = T.get_transition_matrix()
                # predict next turn for intersection i 
                traffic_chain = MarkovChain(transition_matrix=transition_matrix,
                                    states=['left', 'straight', 'right'])
                state = traffic_chain.next_state(current_state=prevState)
                
                #----------------------------------------------------
                # Add Learning data to separate arrays along the way
                #----------------------------------------------------
                
                for row in transition_matrix:
                    for prob in row:
                        flatFeatures.append(prob)
                
                if prevState == "left": flatFeatures.append(0)
                elif prevState == "straight": flatFeatures.append(0.5)
                elif prevState == "right": flatFeatures.append(1)
                
                self.LearningFeatures.append(flatFeatures)
                self.LearningLabels.append(state)
                flatFeatures = []
                #----------------------------------------------------
                
                if prevState == "left":
                    if state == "left":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][0][0]))] #updated number of cars for this step
                    elif state == "straight":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][0][1]))] #cars[i] +  #updated number of cars for this step
                    elif state == "right":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][0][2]))] #updated number of cars for this step

                elif prevState == "straight":
                    if state == "left":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][1][0]))] #updated number of cars for this step
                    if state == "straight":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][1][1]))] #updated number of cars for this step
                    if state == "right":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][1][2]))] #updated number of cars for this step

                elif prevState == "right":
                    if state == "left":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][2][0]))] #updated number of cars for this step
                    if state == "straight":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][2][1]))] #updated number of cars for this step
                    if state == "right":
                        nextTimeStep[i] = [step,
                               #mostRecentTimeStep[i][1], #transition_matrix for vertex
                               transition_matrix,
                               state, 
                               int(self.addNewCars(cars[i]) + self.addActualCars(mostRecentTimeStep[i][3] * mostRecentTimeStep[i][1][2][2]))] #updated number of cars for this step
                
                prevState = state

            
        else:
            nextTimeStep = {}
            prevState = "left"  #initial state at the first intersection
            #init all intersections
            for i in range(len(self.tSteps)):
                # Generate Transition Matrix for intersection i and assign to intersection
                T.gen_state_prob(3,"uniform")
                transition_matrix = T.get_transition_matrix()
                # predict next turn for intersection i 
                traffic_chain = MarkovChain(transition_matrix=transition_matrix,
                                    states=['left', 'straight', 'right'])
                state = traffic_chain.next_state(current_state=prevState)

                #create vertex with all its properties
                nextTimeStep[i] = [10,transition_matrix, state, 0] #0=num_cars
                prevState = state

            #init number of cars at every intersection using Pareto dist RV, t=0
            for vNum, prop in nextTimeStep.items():
                prop[3] = self.lCars[0][vNum]

        self.lMap.append(nextTimeStep)
        #print("Time steps in map:",len(lMap))
        mostRecentTimeStep = {}
        nextTimeStep = {}
        prevState = ""
        #self.LearningFeatures = []
        #self.LearningLabels = []

    def printMap(self,printDetails=False):
        print("vertices:",len(self.lMap[0]))
        print("\t",end="")
        [print('V'+str(i)+'\t',end=("")) for i in range(len(self.lMap[0]))]
        print()
        for i in range(len(self.lMap)):
            print("t=",self.lMap[i][0][0],"\t", end="")
            for vNum, prop in self.lMap[i].items():
                print(prop[3],end="")
                if prop[2] == "left": print("/l\t", end="")
                elif prop[2] == "straight": print("/s\t", end="")
                elif prop[2] == "right": print("/r\t", end="")
            print()

        if printDetails:
            for vNum, prop in self.lMap[0].items():
                print(vNum, "\b:", "Ts:" ,prop[0],"\n",prop[1][0],"\n",prop[1][1],"\n",prop[1][2], "-->" ,prop[2], ", cars(" ,prop[3],")")

    def runSimulation(self, P):
        i = 0
        for steps in self.tSteps:
            P.simulate(steps)                        #simulate next time step
            self.lCars.append(P.get_sim_data(real=True, step=i))
            i+=1
            self.updateMap(self.lMap,self.lCars[len(self.lCars)-1],steps)    #add data cars list
   
    def getLearningData(self):
        return self.LearningFeatures, self.LearningLabels
    
    def generateTestingData(self, count):
        X = Transition(3,3)
        s="" #state
        Ps="right" #prevState
        TM=[] #transition_matrix
        FF=[] #flatFeatures
        self.TestingFeatures=[]
        self.TestingLabels=[]
        for i in range(count):
            X.gen_state_prob(3,"uniform")
            TM = X.get_transition_matrix()
            # predict next turn for intersection i 
            TC = MarkovChain(transition_matrix=TM,
                                states=['left', 'straight', 'right'])
            s = TC.next_state(current_state=Ps)
            

            for row in TM:
                for prob in row:
                    FF.append(prob)

            if Ps == "left": FF.append(0)
            elif Ps == "straight": FF.append(0.5)
            elif Ps == "right": FF.append(1)

            self.TestingFeatures.append(FF)
            self.TestingLabels.append(s)
            Ps = s                                  #current state = previous state for next step
            FF = []
                
    def getTestingData(self):
        return self.TestingFeatures, self.TestingLabels
    
    def plotData(self):
        import matplotlib.pyplot as plt
        import numpy as np
        import datetime
        x = [i for i in range(len(self.tSteps))]
        y=[]
        
        for i in range(len(self.lMap)):
            y.append([])
            for j in range(len(self.lMap[i])):
                y[i].append(self.lMap[i][j][3])
        #print(y)
        """
        #x = np.arange(0, 1.0, 0.01)
        #y1 = np.sin(2*np.pi*x)
        #y2 = np.sin(4*np.pi*x)
        #lines = plt.plot(x, y[0], x, y[1])
        #l1, l2 = lines
        #plt.setp(lines, linestyle='--')       # set both to dashed
        #plt.setp(l1, linewidth=2, color='r')  # line1 is thick and red
        #plt.setp(l2, linewidth=1, color='g')  # line2 is thinner and green
        #plt.plot(x,y)
        
        fig, ax = plt.subplots(1, 1, figsize=(12, 8))
        ax.plot(x, lw=2)
        
        plt.style.use('ggplot')
        
        ax1 = plt.subplot(411)
        plt.plot(x, y[0],color='black',linestyle='--', marker=".")
        #plt.tick_params('x', labelsize=14)
        plt.ylabel("V0", fontsize=14)
        #plt.ylim(0,50,10)
        plt.grid(False)

        # share x only
        ax2 = plt.subplot(412, sharex=ax1)
        plt.plot(x, y[1],color='black',linestyle='--', marker=".")
        # make these tick labels invisible
        #plt.tick_params('x', labelbottom=False)
        #plt.tick_params('x', labelsize=14)
        #plt.ylim(0,50,10)
        plt.ylabel("V1", fontsize=14)
        plt.grid(False)
        
        
        # share x only
        ax3 = plt.subplot(413, sharex=ax1)
        plt.plot(x, y[2],color='black',linestyle='--', marker=".")
        # make these tick labels invisible
        #plt.tick_params('x', labelbottom=False)
        plt.ylabel("V2", fontsize=14)
        #plt.ylim(0,50,10)
        plt.grid(False)

        # share x and y
        ax4 = plt.subplot(414, sharex=ax1, sharey=ax1)
        plt.plot(x, y[3],color='black',linestyle='--', marker=".")
        plt.ylabel("V3", fontsize=14)
        plt.tick_params('x', labelsize=14)
        #plt.ylim(0,50,10)
        plt.xlim(0,20,2)
        plt.xlabel("Time steps", fontsize=14)
        plt.grid(False)
        plt.savefig("plots/cars-timesteps-"+str(datetime.datetime.now())+".png", bbox_inches="tight")
        plt.show()
        
        """
        # line cyclers adapted to colourblind people
        from cycler import cycler
        line_cycler   = (cycler(color=["#E69F00", "#56B4E9", "#009E73", "#0072B2", "#D55E00", "#CC79A7", "#F0E442"]) +
                        cycler(linestyle=["-", "--", "-.", ":", "-", "--", "-."]))
        marker_cycler = (cycler(color=["#E69F00", "#56B4E9", "#009E73", "#0072B2", "#D55E00", "#CC79A7", "#F0E442"]) +
                        cycler(linestyle=["none", "none", "none", "none", "none", "none", "none"]) +
                        cycler(marker=["4", "2", "3", "1", "+", "x", "."]))
        plt.rc("axes", prop_cycle=line_cycler)
        plt.figure()
        #plt.rc("font", family="serif", size=12.)
        plt.rc("savefig", dpi=200)
        plt.rc("legend", loc="best", fontsize="medium", fancybox=True, framealpha=0.5)
        plt.rc("lines", linewidth=2.5, markersize=10, markeredgewidth=2.5)

 
        plt.plot(x, y[0], label="V0")
        plt.plot(x, y[1], label="V1")
        plt.plot(x, y[2], label="V2")
        plt.plot(x, y[3], label="V3")

        #plt.plot(X[0], Y[0])
        #plt.xticks(self.col_names)
        plt.xticks(rotation=90)
        #plt.yticks(np.arange(2400, 12000, step=1000))
        plt.xlabel("Time step", fontsize=14)
        plt.ylabel("Number of cars at intersection", fontsize=14)
        #plt.title(roads[col])
        plt.legend()
        #plt.savefig("plots/cars-timestamps-"+str(datetime.datetime.now())+".png", bbox_inches="tight")
        plt.show()