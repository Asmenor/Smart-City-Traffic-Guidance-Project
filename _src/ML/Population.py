import numpy as np

class Population:
    N = 0
    a = 0
    b = 0
    ntrials = 0
    x = []
    
    def __init__(self, n, A, B, trials):
        self.N = n  # maximum number of cars at an intersection
        self.a = A / self.N  # car arrival rate
        self.b = B / self.N  # car departure rate
        self.ntrials = trials
        self.x = np.random.randint(size=self.ntrials, low=0, high=self.N)
        #print("x: ", self.x)
        self.simulate(10)

    def simulate(self, nsteps, real_data = False):
        """Run the simulation."""
        #self.x = 
        
        if real_data:
            print("real")
        else:
            for _ in range(nsteps - 1):
                # Which trials to update?
                upd = (0 < self.x) & (self.x < self.N - 1)
                # In which trials do births occur?
                ####birth = 1 * (np.random.rand(ntrials) <= a * x)
                birth = 1 * (np.random.pareto(self.ntrials) <= self.a * self.x)
                # In which trials do deaths occur?
                ####death = 1 * (np.random.rand(ntrials) <= b * x)
                death = 1 * (np.random.pareto(self.ntrials) <= self.b * self.x)
                # We update the population size for all trials
                self.x[upd] += birth[upd] - death[upd]
        

    def get_sim_data(self, real=False, step=0):
        if real:
            data = np.load("plots/ShortCountsManhattan.npy",allow_pickle=True)
            #print("lCars: ", data[step][1:])
            return data[step][1:]
        else:
            return self.x