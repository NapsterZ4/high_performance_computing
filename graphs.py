import pandas as pd
import seaborn as sns

df = pd.read_csv("files/data.txt", sep=",")
print(df)

print("Successfully export")