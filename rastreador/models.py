from django.db import models

# Create your models here.

class Data(models.Model):
    Horario = models.FloatField()
    Latitude = models.FloatField()
    Longitude = models.FloatField()
    Altitude = models.FloatField()
    VelocidadeKM = models.FloatField()
    Satelites = models.IntegerField()