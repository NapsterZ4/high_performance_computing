import pandas as pd
import seaborn as sns

workers = {'workers':[1, 2, 4, 8, 16, 32, 64, 128]}
df_speedup = pd.read_csv("files/speedup.txt", sep=" ", names=["iteration", "speedup"])
df_efficiency = pd.read_csv("files/efficiency.txt", sep=" ", names=["iteration", "efficiency"])

df_pworkers = pd.DataFrame(workers)

df = pd.concat([df_pworkers, df_speedup["speedup"], df_efficiency["efficiency"]], axis=1)

sns.set()
g1 = sns.lineplot(x="workers", y="speedup", data=df)
fig = g1.get_figure()
fig.savefig("images/speedup.png")

g2 = sns.lineplot(x="workers", y="efficiency", data=df)
fig2 = g2.get_figure()
fig2.savefig("images/efficiency.png")