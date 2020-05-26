import pandas as pd
import seaborn as sns

df = pd.read_csv("files/data.txt", sep=",")

g = sns.lineplot(x="p", y="efficiency", hue="n", data=df)
g.figure.savefig("images/image1.png", dpi=200)

g = sns.lineplot(x="n", y="efficiency", hue="p", data=df)
g.figure.savefig("images/image2.png", dpi=200)

g = sns.lineplot(x="p", y="speedup", hue="n", data=df)
g.figure.savefig("images/image3.png", dpi=200)

g = sns.lineplot(x="n", y="speedup", hue="p", data=df)
g.figure.savefig("images/image4.png", dpi=200)

print("Successfully graphs export in images/")