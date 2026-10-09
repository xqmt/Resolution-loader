local Players = game:GetService("Players")
local CoreGui = game:GetService("CoreGui")
local TweenService = game:GetService("TweenService")
local RunService = game:GetService("RunService")

local gui = Instance.new("ScreenGui")
gui.Name = "nebula.hit_loader"
gui.ResetOnSpawn = false
gui.IgnoreGuiInset = true

pcall(function() gui.Parent = CoreGui end)
if not gui.Parent then
    gui.Parent = Players.LocalPlayer:WaitForChild("PlayerGui")
end

local loadingOverlay = Instance.new("Frame")
loadingOverlay.Name = "LoadingOverlay"
loadingOverlay.Size = UDim2.new(1, 0, 1, 0)
loadingOverlay.Position = UDim2.new(0, 0, 0, 0)
loadingOverlay.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
loadingOverlay.BackgroundTransparency = 0
loadingOverlay.BorderSizePixel = 0
loadingOverlay.ZIndex = 999999
loadingOverlay.Parent = gui

local centerContainer = Instance.new("Frame")
centerContainer.Name = "CenterContainer"
centerContainer.Size = UDim2.new(0, 600, 0, 240)
centerContainer.Position = UDim2.new(0.5, -300, 0.5, -120)
centerContainer.BackgroundTransparency = 1
centerContainer.ZIndex = 1000000
centerContainer.Parent = loadingOverlay

local centerLayout = Instance.new("UIListLayout")
centerLayout.FillDirection = Enum.FillDirection.Vertical
centerLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
centerLayout.VerticalAlignment = Enum.VerticalAlignment.Center
centerLayout.SortOrder = Enum.SortOrder.LayoutOrder
centerLayout.Padding = UDim.new(0, 10)
centerLayout.Parent = centerContainer

local loadingIcon = Instance.new("ImageLabel")
loadingIcon.Name = "LoadingIcon"
loadingIcon.Size = UDim2.new(0, 100, 0, 100)
loadingIcon.BackgroundTransparency = 1
loadingIcon.Image = "https://www.roblox.com/asset-thumbnail/image?assetId=17118402590&width=420&height=420&format=png"
loadingIcon.ImageTransparency = 1
loadingIcon.ZIndex = 1000001
loadingIcon.LayoutOrder = 1
loadingIcon.Parent = centerContainer

local textContainer = Instance.new("Frame")
textContainer.Name = "TextContainer"
textContainer.Size = UDim2.new(1, 0, 0, 60)
textContainer.BackgroundTransparency = 1
textContainer.ZIndex = 1000000
textContainer.LayoutOrder = 2
textContainer.Parent = centerContainer

local textLayout = Instance.new("UIListLayout")
textLayout.FillDirection = Enum.FillDirection.Horizontal
textLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
textLayout.VerticalAlignment = Enum.VerticalAlignment.Center
textLayout.SortOrder = Enum.SortOrder.LayoutOrder
textLayout.Padding = UDim.new(0, 0)
textLayout.Parent = textContainer

local titleText = "Swiftly.fly"
local letterLabels = {}

for i = 1, #titleText do
    local char = string.sub(titleText, i, i)
    local letterLabel = Instance.new("TextLabel")
    letterLabel.Name = "Char_" .. i
    letterLabel.Size = UDim2.new(0, (char == "." and 18 or 32), 1, 0)
    letterLabel.BackgroundTransparency = 1
    letterLabel.Text = char
    letterLabel.Font = Enum.Font.Cartoon
    letterLabel.TextSize = 56
    letterLabel.TextTransparency = 1
    letterLabel.ZIndex = 1000001
    letterLabel.Parent = textContainer

    table.insert(letterLabels, {
        Label = letterLabel,
        Char = char,
        Index = i
    })
end

local whiteBaseColor = Color3.fromRGB(255, 255, 255)
local flyBaseColor = Color3.fromHex("#a0bdff")

local loadingWaveConn = RunService.RenderStepped:Connect(function()
    local t = os.clock() * 4.5
    for _, item in ipairs(letterLabels) do
        local offset = item.Index * 0.35
        local val = (math.sin(t - offset) + 1) / 2
        
        if item.Index >= 8 then
        
            item.Label.TextColor3 = Color3.new(
                flyBaseColor.R * (0.65 + 0.35 * val),
                flyBaseColor.G * (0.65 + 0.35 * val),
                flyBaseColor.B * (0.65 + 0.35 * val)
            )
        else
            local brightness = 0.65 + 0.35 * val
            item.Label.TextColor3 = Color3.new(brightness, brightness, brightness)
        end
    end
end)

local creditLabel = Instance.new("TextLabel")
creditLabel.Name = "CreditLabel"
creditLabel.Size = UDim2.new(1, 0, 0, 20)
creditLabel.BackgroundTransparency = 1
creditLabel.Text = "Credit to @Wick2funny"
creditLabel.Font = Enum.Font.Cartoon
creditLabel.TextSize = 14
creditLabel.TextColor3 = Color3.fromRGB(150, 150, 160)
creditLabel.TextTransparency = 1
creditLabel.ZIndex = 1000001
creditLabel.LayoutOrder = 3
creditLabel.Parent = centerContainer

local rotationConnection = RunService.RenderStepped:Connect(function(delta)
    if loadingIcon and loadingIcon.Parent then
        loadingIcon.Rotation = (loadingIcon.Rotation + delta * 180) % 360
    end
end)

TweenService:Create(loadingIcon, TweenInfo.new(0.8), {ImageTransparency = 0}):Play()
task.wait(0.4)

for index, item in ipairs(letterLabels) do
    item.Label.Position = UDim2.new(0, 0, 0, 15)
    TweenService:Create(item.Label, TweenInfo.new(0.6, Enum.EasingStyle.Back, Enum.EasingDirection.Out), {
        TextTransparency = 0,
        Position = UDim2.new(0, 0, 0, 0)
    }):Play()
    task.wait(0.08)
end

TweenService:Create(creditLabel, TweenInfo.new(0.6, Enum.EasingStyle.Quad, Enum.EasingDirection.Out), {
    TextTransparency = 0
}):Play()

task.wait(3) 

TweenService:Create(loadingIcon, TweenInfo.new(0.6), {ImageTransparency = 1}):Play()
TweenService:Create(creditLabel, TweenInfo.new(0.5, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {
    TextTransparency = 1
}):Play()

for index, item in ipairs(letterLabels) do
    TweenService:Create(item.Label, TweenInfo.new(0.5, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {
        TextTransparency = 1,
        Position = UDim2.new(0, 0, 0, -15)
    }):Play()
end

TweenService:Create(loadingOverlay, TweenInfo.new(0.8, Enum.EasingStyle.Quad, Enum.EasingDirection.Out), {BackgroundTransparency = 1}):Play()

task.wait(3)
if rotationConnection then rotationConnection:Disconnect() end
if loadingWaveConn then loadingWaveConn:Disconnect() end
gui:Destroy()

loadstring(game:HttpGet("https://raw.githubusercontent.com/xqmt/Resolution-loader/refs/heads/main/Resolution.lua.txt"))()
