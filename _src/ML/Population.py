import numpy as np

class Population:
    N = 0
    a = 0
    b = 0
    n_intersections = 0
    rnd_cars = []
    
    def __init__(self, n, A, B, no_intersections):
        self.N = n  # marnd_carsimum number of rnd_cars at an intersection
        self.a = A / self.N  # car arrival rate
        self.b = B / self.N  # car departure rate
        self.n_intersections = no_intersections # num intersections
        self.rnd_cars = np.random.randint(size=self.n_intersections, low=0, high=self.N)
        #print("rnd_cars: ", self.rnd_cars)
        self.simulate(10)

    def simulate(self, nsteps, real_data = False):
        """Run the simulation."""
        #self.rnd_cars = 
        
        if real_data:
            print("real")
        else:
            for _ in range(nsteps - 1):
                # Which trials to update?
                upd = (0 < self.rnd_cars) & (self.rnd_cars < self.N - 1)
                # In which trials do births occur?
                ####birth = 1 * (np.random.rand(n_intersections) <= a * rnd_cars)
                birth = 1 * (np.random.pareto(self.n_intersections) <= self.a * self.rnd_cars)
                # In which trials do deaths occur?
                ####death = 1 * (np.random.rand(n_intersections) <= b * rnd_cars)
                death = 1 * (np.random.pareto(self.n_intersections) <= self.b * self.rnd_cars)
                # We update the population size for all trials
                self.rnd_cars[upd] += birth[upd] - death[upd]
        

    def get_sim_data(self, real=False, step=0):
        """
        return actual or random no of cars list depending on bool real
        """
        if real:
            actual_cars = np.load("plots/ShortCountsManhattan.npy",allow_pickle=True)
            print("rnd_cars: ", actual_cars[step][1:])
            return actual_cars[step][1:]
        else:
            return self.rnd_cars


P = Population(20,0.5,0.5,38)
print(P.get_sim_data())