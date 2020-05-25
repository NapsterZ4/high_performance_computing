import pandas as pd
import seaborn as sns

df_serial = pd.read_csv("serial.txt", sep=" ", names=["iteration", "value_serial"])
df_parallel = pd.read_csv("parallel.txt", sep=" ", names=["iteration", "value_parallel"])
df_serial = pd.DataFrame(df_serial)
df_parallel = pd.DataFrame(df_parallel)

df = pd.concat([df_serial["value_serial"], df_parallel], axis=1)

sns.set()
g1 = sns.regplot(x="iteration", y="value_serial", data=df)
fig = g1.get_figure()
fig.savefig("value_serial.png")

g2 = sns.regplot(x="iteration", y="value_parallel", data=df)
fig2 = g2.get_figure()
fig2.savefig("value_parallel.png")

g3 = sns.regplot(x="value_serial", y = "value_parallel", data=df)
fig3 = g3.get_figure()
fig3.savefig("all_values.png")