from django.shortcuts import render
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
import json
from rastreador.models import Data

# Create your views here.

@csrf_exempt
def rastreio(request):
    if request.method == 'POST':
        try:
            data = json.loads(request.body)

            latitude = data.get('lat')
            longitude = data.get('lng')
            altitude = data.get('alt')
            minutos = data.get('min')
            velocidade = data.get('kmp')
            satelites = data.get('sat')

            data_create = Data(Latitude = latitude, 
                               Longitude = longitude, 
                               Altitude = altitude, 
                               Horario = minutos, 
                               VelocidadeKM = velocidade, 
                               Satelites = satelites)
            data_create.save()




            response_data = {'status': 'sucess', 'received_data': data}
            return JsonResponse(response_data)
    
        except Exception as error:
            return JsonResponse({'status': 'error', 'message': 'Invalid JSON', "error": str(error)}, status=400)
    else:
        return JsonResponse({'status': 'error', 'message': 'Invalid method'}, status=405)
