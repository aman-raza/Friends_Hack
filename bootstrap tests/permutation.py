import numpy as np
import matplotlib.pyplot as plt

def permutation_test(first_array, second_array, resampling=30000, print_result=True, seed=0):

    np.random.seed = seed

    H0_diff = abs(first_array.mean() - second_array.mean())

    total_array = np.hstack([first_array, second_array])

    mean_diffs = []

    for _ in range(resampling):

        np.random.shuffle(total_array)

        random_first_array = total_array[:first_array.shape[0]]
        random_second_array = total_array[first_array.shape[0]:]

        mean_diff = abs(random_first_array.mean() - random_second_array.mean())
        mean_diffs.append(mean_diff)

    nb_extreme_values = 0

    for min_diff in mean_diffs:
        if min_diff > abs(H0_diff):
            nb_extreme_values += 1

    p_value = nb_extreme_values / len(mean_diffs)

    if print_result : print(f"P-value is {p_value:.2f}")
    return p_value
