from abc import ABC, abstractmethod

class VehicleBase(ABC):
    @abstractmethod
    def __init__(self, name, speed, range, hp):
        self.name = name
        self.speed = speed
        self.range = range
        self.power = hp

    @abstractmethod
    def get_details(self) -> str:
        s = str('Details: \r\n\tName: {} \r\n\t0-60 speed = {} s \r\n\tRange = {} mile \r\n\tPower = {} hp'.format(self.name, self.speed, self.range, self.power))
        return s