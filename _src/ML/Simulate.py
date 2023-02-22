
from MarkovProcess import MarkovChain
from Transition import Transition


class Simulate:

    def __init__(self, steps):
        self.lMap = []  # holds all timeSteps/snapshots from the map
        self.lCars = []
        self.addCars = False  # True: adds cars at every time step
        self.addActCars = False # True: only adds actual cars data. False: adds random car data
        self.LearningFeatures = []
        self.LearningLabels = []
        self.TestingFeatures = []
        self.TestingLabels = []
        self.tSteps = steps

    def updateTransitionMatrix(self, tm_0, tm_1, cars_0, cars_1):
        # how to change transition matrix when new cars are added
        return tm_1

    # if true, adds new cars to intersection
    # if false, carries over only the cars coming in from previous intersections
    def addNewCars(self, cars):
        if self.addCars:
            return cars
        else:
            return 0

    def addActualCars(self, cars):
        if self.addActCars:
            return 0
        else:
            return cars

    # updates lMap with newly added cars after every time period
    def updateMap(self, cars, step):
        """
        Creates a map and also creates learning/testing data
        """
        flat_features = []
        #dVertices[i] = {0, [step,[[transition_matrix]], state, 0]}
        T = Transition(3, 3)

        if len(self.lMap) > 0:
            most_recent_timestep = self.lMap[(len(self.lMap)-1)]
            # print("most_recent_timestep",most_recent_timestep)
            next_time_step = {}
            # copy previous state from last time step
            prev_state = most_recent_timestep[0][2]

            for i in range(len(cars)):
                # Generate Transition Matrix for intersection i and assign to intersection
                T.gen_state_prob(3, "uniform")
                transition_matrix = T.get_transition_matrix()
                # predict next turn for intersection i
                traffic_chain = MarkovChain(transition_matrix=transition_matrix,
                                            states=['left', 'straight', 'right'])
                state = traffic_chain.next_state(current_state=prev_state)

                # ----------------------------------------------------
                # Add Learning data to separate arrays along the way
                # ----------------------------------------------------

                for row in transition_matrix:
                    for prob in row:
                        flat_features.append(prob)

                if prev_state == "left":
                    flat_features = flat_features + [1, 0, 0]
                elif prev_state == "straight":
                    flat_features = flat_features + [0, 1, 0]
                elif prev_state == "right":
                    flat_features = flat_features + [0, 0, 1]

                self.LearningFeatures.append(flat_features)
                self.LearningLabels.append(state)
                flat_features = []
                # ----------------------------------------------------

                if prev_state == "left":
                    if state == "left":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][0][0]))]  # updated number of cars for this step
                    elif state == "straight":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][0][1]))]  # cars[i] +  #updated number of cars for this step
                    elif state == "right":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][0][2]))]  # updated number of cars for this step

                elif prev_state == "straight":
                    if state == "left":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][1][0]))]  # updated number of cars for this step
                    if state == "straight":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][1][1]))]  # updated number of cars for this step
                    if state == "right":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][1][2]))]  # updated number of cars for this step

                elif prev_state == "right":
                    if state == "left":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][2][0]))]  # updated number of cars for this step
                    if state == "straight":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][2][1]))]  # updated number of cars for this step
                    if state == "right":
                        next_time_step[i] = [step,
                                             # most_recent_timestep[i][1], #transition_matrix for vertex
                                             transition_matrix,
                                             state,
                                             int(self.addNewCars(cars[i]) + self.addActualCars(most_recent_timestep[i][3] * most_recent_timestep[i][1][2][2]))]  # updated number of cars for this step

                prev_state = state

        else:
            next_time_step = {}
            prev_state = "left"  # initial state at the first intersection
            # init all intersections
            for i in range(len(cars)):
                # Generate Transition Matrix for intersection i and assign to intersection
                T.gen_state_prob(3, "uniform")
                transition_matrix = T.get_transition_matrix()
                # predict next turn for intersection i
                traffic_chain = MarkovChain(transition_matrix=transition_matrix,
                                            states=['left', 'straight', 'right'])
                state = traffic_chain.next_state(current_state=prev_state)

                # create vertex with all its properties
                next_time_step[i] = [10, transition_matrix, state, self.lCars[0][i]]  # 0=num_cars
                prev_state = state
            # init number of cars at every intersection using Pareto dist RV, t=0
            """
            print("len(self.lCars[0]",len(self.lCars[0]),"self.lCars[0]", self.lCars[0])
            print("len(next_time_step):",len(next_time_step),"next_time_step:",next_time_step)
            for vertex_num, prop in next_time_step.items():
                prop[3] = self.lCars[0][vertex_num]
                print("vertex_num:", vertex_num, "prop:", prop, end=" ")
                print("prop[3]", prop[3])
            """
            print("next_time_step", next_time_step)
            
        self.lMap.append(next_time_step)
        most_recent_timestep = {}
        next_time_step = {}
        prev_state = ""
        
    def printMap(self, print_details=False):
        print("vertices:", len(self.lMap[0]))
        print("\t", end="")
        for i in range(len(self.lMap[0])):
            print('V'+str(i)+'\t', end=(""))
        print()
        for i in range(len(self.lMap)):
            print("t=", self.lMap[i][0][0], "\t", end="")
            for vertex_num, prop in self.lMap[i].items():
                print(prop[3], end="")
                if prop[2] == "left":
                    print("/l\t", end="")
                elif prop[2] == "straight":
                    print("/s\t", end="")
                elif prop[2] == "right":
                    print("/r\t", end="")
            print()

        if print_details:
            for vertex_num, prop in self.lMap[0].items():
                print(vertex_num, "\b:", "Ts:", prop[0], "\n", prop[1][0], "\n", prop[1][1], "\n", prop[1][2], "-->", prop[2], ", cars(", prop[3], ")")

    def runSimulation(self, P):
        i = 0
        for step in self.tSteps:
            P.simulate(step)  # simulate next time step
            self.lCars.append(P.get_sim_data(real=False, step=i))
            i += 1
            # add data cars list
            self.updateMap(self.lCars[len(self.lCars)-1], step)

    def getLearningData(self):
        return self.LearningFeatures, self.LearningLabels

    def generateTestingData(self, count):
        X = Transition(3, 3)
        s = ""  # state
        Ps = "right"  # prev_state
        TM = []  # transition_matrix
        FF = []  # flat_features
        self.TestingFeatures = []
        self.TestingLabels = []
        for i in range(count):
            X.gen_state_prob(3, "uniform")
            TM = X.get_transition_matrix()
            # predict next turn for intersection i
            TC = MarkovChain(transition_matrix=TM,
                             states=['left', 'straight', 'right'])
            s = TC.next_state(current_state=Ps)

            for row in TM:
                for prob in row:
                    FF.append(prob)

            if Ps == "left":
                FF = FF+[1, 0, 0]
            elif Ps == "straight":
                FF = FF+[0, 1, 0]
            elif Ps == "right":
                FF = FF+[0, 0, 1]

            self.TestingFeatures.append(FF)
            self.TestingLabels.append(s)
            Ps = s  # current state = previous state for next step
            FF = []

    def getTestingData(self):
        return self.TestingFeatures, self.TestingLabels

    def plotData(self):
        import matplotlib.pyplot as plt
        import numpy as np
        import datetime
        x = [i for i in range(len(self.lMap[0]))]
        y = []

        for i in range(len(self.tSteps)):
            y.append([])
            for j in range(len(self.lMap[i])):
                y[i].append(self.lMap[i][j][3])
        print("x:", x)
        print("y:", y)

        # line cyclers adapted to colourblind people
        from cycler import cycler
        line_cycler = (cycler(color=["#E69F00", "#56B4E9", "#009E73", "#0072B2", "#D55E00", "#CC79A7", "#F0E442"]) +
                       cycler(linestyle=["-", "--", "-.", ":", "-", "--", "-."]))
        marker_cycler = (cycler(color=["#E69F00", "#56B4E9", "#009E73", "#0072B2", "#D55E00", "#CC79A7", "#F0E442"]) +
                         cycler(linestyle=["none", "none", "none", "none", "none", "none", "none"]) +
                         cycler(marker=["4", "2", "3", "1", "+", "x", "."]))
        plt.rc("axes", prop_cycle=line_cycler)
        plt.figure()
        #plt.rc("font", family="serif", size=12.)
        plt.rc("savefig", dpi=200)
        plt.rc("legend", loc="best", fontsize="medium",
               fancybox=True, framealpha=0.5)
        plt.rc("lines", linewidth=2.5, markersize=10, markeredgewidth=2.5)

        plt.plot(x, y[0], label="T0")
        plt.plot(x, y[10], label="T10")
        plt.plot(x, y[20], label="T20")
        plt.plot(x, y[30], label="T30")

        #plt.plot(X[0], Y[0])
        # plt.xticks(self.col_names)
        plt.xticks(rotation=90)
        #plt.yticks(np.arange(2400, 12000, step=1000))
        plt.xlabel("Intersection", fontsize=14)
        plt.ylabel("Number of cars at intersection", fontsize=14)
        # plt.title(roads[col])
        plt.legend()
        #plt.savefig("plots/cars-timestamps-"+str(datetime.datetime.now())+".png", bbox_inches="tight")
        plt.show()

    def getLMap(self):
        return self.lMap

    def getLCars(self):
        return self.lCars

    def getTimeSteps(self):
        return self.tSteps