class MyModule:
  def execute(self, data):
    print(f'Inside Python: name = {data.str}, vector = {data.v}')
    return sum(data.v)