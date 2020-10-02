import numpy as np

def bootstrap_test(tested_array, H0_mean, sampling = 10_000, seed=0, print_result=True):

  """This function outputs the probability of obtaining the observed difference between the mean of the tested_array and the H0_mean, given that the HO_mean is true (P-value).
  Type hints :
    tested_array : np.array()
    HO_mean : int or float
    sampling : int
    seed : int"""

  np.random.seed(seed)

  simulated_sample_means = [np.random.choice(tested_array,
                                  size=tested_array.shape[0],
                                  replace=True).mean()
                                  for _ in range(sampling)]

  array_mean = tested_array.mean()
  interval = [array_mean - abs(array_mean - H0_mean), array_mean + abs(array_mean - H0_mean)]

  number_extreme_values = 0
  for sample_mean in simulated_sample_means:
      if not interval[0] < sample_mean < interval[1]:
          number_extreme_values += 1

  p_value =  number_extreme_values / len(simulated_sample_means)

  if print_result == True :  print(f"P-value is approximately {p_value:.2f}")
  
  return p_value
