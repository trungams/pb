from src.pyembed.datamodule import IntMatrix
import numpy as np

class MyModule:
    def execute(self, data):
        print(f'Inside Python: name = {data.str}, vector = {data.v}')
        return sum(data.v)

    def multiply_matrices(self, a, b):
        print("inside python")
        m_a = np.array(a, copy=False)
        m_b = np.array(b, copy=False)
        print(m_a)
        print(m_b)
        print(np.dot(m_a, m_b))
        return IntMatrix(np.dot(m_a, m_b))
