class Vlogger():
    company = "youtube"

    def __init__(self, subscribe):
        self.subscribe = subscribe

    def subscriberCount(self):
        if self.subscribe > 0:
            print(f"Your subscriber count is {self.subscribe}")
            self.subscribe += 1


v = Vlogger(2)
print(v.company)
v.subscriberCount()
