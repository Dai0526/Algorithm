from Vehicle.ModelX import ModelX
from Vehicle.ModelY import ModelY
from TeslaFactory.SUVFactoryBase import SUVFactoryBase

class SUVFactoryPerformance(SUVFactoryBase):

    def create_model_x(self) -> ModelX:
        x = ModelX("ModelX", 2.5, 340, 1020, "2022", 119990)
        x.type = "Performance"
        x.description = "Tri Motor All-Wheel Drive"
        return x

    def create_model_y(self) -> ModelY:
        y = ModelY("ModelY", 3.5, 303, 456, "2022", 55190)
        y.type = "Performance"
        y.description = "Dual Motor All-Wheel Drive"
        return y