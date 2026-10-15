import yfinance as yf
import pandas as pd

# 30 actions liquides réparties sur 6 secteurs variés
tickers = [
    "AAPL", "MSFT", "NVDA", "GOOGL", "META",  # Technologie
    "XOM", "CVX", "COP", "SLB", "EOG",        # Énergie
    "JPM", "BAC", "WFC", "GS", "MS",          # Finance
    "JNJ", "UNH", "PFE", "ABBV", "MRK",       # Santé
    "AMZN", "WMT", "PG", "KO", "PEP",         # Consommation
    "CAT", "BA", "VZ", "T", "DIS"             # Industrie & Telecom
]

print("Téléchargement des données en cours...")
data = yf.download(tickers, period="5y")

# Extraction des cours de clôture ajustés
prices = data['Adj Close']

# Traitement des valeurs manquantes : 
# 1. On propage le dernier prix connu en cas de trou (forward fill)
# 2. On supprime les jours totalement vides (ex: week-ends/jours fériés)
prices = prices.ffill().dropna()

prices.to_csv("data/prices.csv")
print("Données sauvegardées dans data/prices.csv")